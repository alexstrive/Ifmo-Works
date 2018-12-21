package io.github.novopashin.requests;

import java.math.BigDecimal;

public class ChargePercentageRequest extends Request {
    private double percentage;
    public ChargePercentageRequest(double percentage) {
        super();
        this.percentage = percentage;
    }

    @Override
    public boolean execute() {
        var percentage = BigDecimal.valueOf(this.percentage);
        var absolutePercentage = this.account.amount().multiply(percentage);
        this.account.deposit(absolutePercentage.doubleValue());

        if (getNext() == null) {
            return true;
        }

        return getNext().execute();
    }
}
