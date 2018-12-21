package io.github.novopashin.account.specific;

import io.github.novopashin.account.Account;
import io.github.novopashin.account.modificators.Amount;
import io.github.novopashin.Client;
import io.github.novopashin.account.modificators.Operation;
import io.github.novopashin.account.AccountDecorator;

@Amount.Min(0.00)
public class CurrentAccount extends AccountDecorator implements Account {
    public CurrentAccount(Client owner) {
        super(owner);
    }

    @Override
    @Operation.Limit(50_000.00)
    public void withdraw(double amount) {
        super.withdraw(amount);
    }

    @Override
    public void deposit(double amount) {
        super.deposit(amount);
    }
}
