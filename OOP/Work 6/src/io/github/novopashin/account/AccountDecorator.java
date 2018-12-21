package io.github.novopashin.account;

import io.github.novopashin.Client;
import io.github.novopashin.account.modificators.Amount;

import java.math.BigDecimal;

import static io.github.novopashin.account.modificators.Operation.*;

public abstract class AccountDecorator {
    private BasicAccount decorative;
    private BigDecimal MAX_AMOUNT;
    private BigDecimal MIN_AMOUNT;

    public AccountDecorator(Client owner) {
        this.decorative = new BasicAccount(owner);

        var amountMax = ((Amount.Max) this.getClass().getAnnotation(Amount.Max.class));
        if (amountMax != null) {
            this.MAX_AMOUNT = BigDecimal.valueOf(amountMax.value());
        }

        var amountMin = ((Amount.Min) this.getClass().getAnnotation(Amount.Min.class));
        if (amountMin != null) {
            this.MIN_AMOUNT = BigDecimal.valueOf(amountMin.value());
        }
    }

    public void withdraw(double amount) {
        try {
            if (MIN_AMOUNT != null && this.decorative.amount.subtract(BigDecimal.valueOf(amount)).compareTo(MIN_AMOUNT) < 0) {
                throw new Exception("Данный лицевой счет не может содержать менее " + MIN_AMOUNT + " RUB");
            }

            handleOperation("withdraw", BigDecimal.valueOf(amount));
            decorative.withdraw(amount);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void deposit(double amount) {
        try {
            if (MAX_AMOUNT != null && this.decorative.amount.add(BigDecimal.valueOf(amount)).compareTo(MAX_AMOUNT) > 0) {
                throw new Exception("Данный лицевой счет не может содержать более " + MAX_AMOUNT + " RUB");
            }

            handleOperation("deposit", BigDecimal.valueOf(amount));
            decorative.deposit(amount);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    private void handleOperation(String name, BigDecimal amount) throws Exception {
        var annotations = this.getClass()
                .getMethod(name, double.class)
                .getDeclaredAnnotations();

        for (var annotation : annotations) {

            if (annotation.annotationType() == Limit.class) {
                var limit = (Limit) annotation;

                var operationMax = new BigDecimal(limit.value());
                var isForShady = limit.forShady();

                handleOperationLimit(amount, operationMax, isForShady);
            }

            if (annotation.annotationType() == UsageCommission.class) {
                var commission = (UsageCommission) annotation;
                var percent = commission.value();
                var isForNegative = commission.forNegative();
                handleUsageCommission(amount, percent, isForNegative);
            }
        }
    }

    private void handleOperationLimit(BigDecimal amount,
                                      BigDecimal max,
                                      boolean isForShady) throws Exception {
        // Skip irrelevant accounts
        if (isForShady && !this.decorative.owner.isShady()) {
            return;
        }

        if (amount.compareTo(max) > 0) {
            throw new Exception("Данный лицевой счет имеет ограниченние на данную операцию: " + max + " RUB");
        }
    }

    private void handleUsageCommission(BigDecimal amount,
                                       double percent,
                                       boolean isForNegative) {
        var currentAmount = this.decorative.amount;

        if (isForNegative && currentAmount.compareTo(BigDecimal.ZERO) == 1) {
            return;
        }

        var absoluteCommission = currentAmount.add(amount).multiply(BigDecimal.valueOf(percent));

        this.decorative.amount = this.decorative.amount.subtract(absoluteCommission);
    }

    public void transfer(Account target, double amount) throws Exception {
        if (!target.hasTargetOwner(this.decorative.owner)) {
            throw new Exception("Денежные средства можно переводить только между своими счетами");
        }

        this.decorative.transfer(target, amount);
    }

    public boolean hasTargetOwner(Client owner) {
        return owner.equals(this.decorative.owner);
    }

    public BigDecimal amount() {
        return decorative.amount();
    }

    private class BasicAccount implements Account {
        private Client owner;
        private BigDecimal amount;

        BasicAccount(Client owner) {
            this.owner = owner;
            this.amount = new BigDecimal(0);
        }

        public void withdraw(double amount) {
            this.amount = this.amount.subtract(BigDecimal.valueOf(amount));
        }

        public void deposit(double amount) {
            this.amount = this.amount.add(BigDecimal.valueOf(amount));
        }

        @Override
        public void transfer(Account target, double amount) {
            this.withdraw(amount);
            target.deposit(amount);
        }

        @Override
        public boolean hasTargetOwner(Client owner) {
            return false;
        }

        @Override
        public BigDecimal amount() {
            return this.amount;
        }
    }
}