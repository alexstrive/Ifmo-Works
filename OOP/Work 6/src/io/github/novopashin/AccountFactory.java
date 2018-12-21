package io.github.novopashin;

import io.github.novopashin.account.Account;
import io.github.novopashin.account.specific.CreditAccount;
import io.github.novopashin.account.specific.CurrentAccount;
import io.github.novopashin.account.specific.DepositAccount;

import java.time.LocalDate;

public class AccountFactory {
    private Client owner;

    public AccountFactory(Client owner) {
        this.owner = owner;
    }

    public Account create(Account.Type type) {
        switch (type) {
            case DEPOSIT:
                return new DepositAccount(owner, LocalDate.now().plusYears(2));
            case CREDIT:
                return new CreditAccount(owner);
            case CURRENT:
                return new CurrentAccount(owner);
        }

        return null;
    }
}
