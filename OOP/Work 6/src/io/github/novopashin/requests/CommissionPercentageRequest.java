package io.github.novopashin.requests;

import java.math.BigDecimal;

public class CommissionPercentageRequest extends Request {
    private double percentage;

    public CommissionPercentageRequest(double percentage) {
        this.percentage = percentage;
    }

    @Override
    public boolean execute() {
        var percentage = BigDecimal.valueOf(this.percentage);
        var absolutePercentage = this.account.amount().multiply(percentage);
        this.account.withdraw(absolutePercentage.doubleValue());

        if (getNext() == null) {
            return true;
        }

        return getNext().execute();
    }
}
