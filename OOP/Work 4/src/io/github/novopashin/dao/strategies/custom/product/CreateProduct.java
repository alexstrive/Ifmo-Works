package io.github.novopashin.dao.strategies.custom.product;

import io.github.novopashin.dao.strategies.general.Targetable;
import io.github.novopashin.dao.strategies.general.CreateStrategy;

public abstract class CreateProduct extends Targetable implements CreateStrategy {
    public CreateProduct(Object targetObjectName) {
        super(targetObjectName);
    }
}
