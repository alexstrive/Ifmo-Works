package io.github.novopashin.dao.strategies.custom.product;

import io.github.novopashin.dao.strategies.general.HasStrategy;
import io.github.novopashin.dao.strategies.general.Targetable;

public abstract class FilterProduct extends Targetable implements HasStrategy {
    public FilterProduct(Object targetObject) {
        super(targetObject);
    }

    protected String getFilename() {
        return getTargetObject().toString();
    }
}
