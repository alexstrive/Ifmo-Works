package io.github.novopashin.account.specific;

import io.github.novopashin.account.Account;
import io.github.novopashin.account.modificators.Amount;
import io.github.novopashin.Client;
import io.github.novopashin.account.AccountDecorator;

import java.time.LocalDate;

@Amount.Min(0)
public class DepositAccount extends AccountDecorator implements Account {
    private LocalDate targetDate;

    public DepositAccount(Client owner, LocalDate date) {
        super(owner);
        this.targetDate = date;
    }

    @Override
    public void withdraw(double amount) {
        try {
            var now = LocalDate.now();
            if (now.isBefore(targetDate)) {
                throw new Exception("Невозможно снять денежные средства с данного депозитного счета до " + targetDate);
            }

            super.withdraw(amount);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    @Override
    public void deposit(double amount) {
        super.deposit(amount);
    }
}
