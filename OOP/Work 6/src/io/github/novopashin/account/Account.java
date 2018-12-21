package io.github.novopashin.account;

import io.github.novopashin.Client;
import io.github.novopashin.requests.Request;

import java.math.BigDecimal;

public interface Account {
    void withdraw(double amount);

    void deposit(double amount);

    void transfer(Account target, double amount) throws Exception;

    boolean hasTargetOwner(Client owner);

    BigDecimal amount();

    enum Type {
        CREDIT,
        CURRENT,
        DEPOSIT,
    }

    default boolean send(Request request) {
        return request.attach(this).execute();
    }

}
