package io.github.novopashin.dao.strategies.custom.store;

import io.github.novopashin.dao.strategies.general.HasStrategy;
import io.github.novopashin.dao.strategies.general.Targetable;

public abstract class HasStore extends Targetable implements HasStrategy {
    public HasStore(Object targetObject) {
        super(targetObject);
    }

    protected String getFilename() {
        return getTargetObject().toString();
    }
}
