package io.github.novopashin.account.specific;

import io.github.novopashin.Client;
import io.github.novopashin.account.Account;
import io.github.novopashin.account.modificators.Operation;
import io.github.novopashin.account.AccountDecorator;

public class CreditAccount extends AccountDecorator implements Account {
    public CreditAccount(Client owner) {
        super(owner);
    }

    @Override
    @Operation.UsageCommission(0.18)
    public void withdraw(double amount) {
        super.withdraw(amount);
    }

    @Override
    @Operation.UsageCommission(0.20)
    public void deposit(double amount) {
        super.deposit(amount);
    }
}
