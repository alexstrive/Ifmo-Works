package io.github.novopashin.requests;

import io.github.novopashin.account.Account;

import java.util.Map;

public class Request {
    private Request next;
    protected Account account;

    public void setNext(Request next) {
        this.next = next;
    }

    public Request getNext() {
        return next;
    }

    public boolean execute() {
        if (next == null) {
            return true;
        }

        return next.execute();
    }

    public Request attach(Account account) {
        this.account = account;
        if (getNext() != null) {
            getNext().attach(account);
        }
        return this;
    }

    public Request with(Request request) {
        setNext(request);
        return request;
    }
}
