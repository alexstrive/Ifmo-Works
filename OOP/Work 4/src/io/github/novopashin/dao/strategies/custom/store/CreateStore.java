package io.github.novopashin.dao.strategies.custom.store;

import io.github.novopashin.dao.strategies.general.Targetable;
import io.github.novopashin.dao.strategies.general.CreateStrategy;

public abstract class CreateStore extends Targetable implements CreateStrategy {
    public CreateStore(String targetObjectName) {
        super(targetObjectName);
    }

    protected String getFilename() {
        return getTargetObject().toString();
    }
}
