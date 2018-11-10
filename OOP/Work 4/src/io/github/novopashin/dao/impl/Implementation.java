package io.github.novopashin.dao.impl;

import io.github.novopashin.dao.strategies.general.CreateStrategy;
import io.github.novopashin.dao.strategies.general.FilterStrategy;
import io.github.novopashin.dao.strategies.general.HasStrategy;

import java.util.ArrayList;
import java.util.HashMap;

public abstract class Implementation {
    private CreateStrategy createStrategy;
    private FilterStrategy filterStrategy;
    private HasStrategy hasStrategy;

    public Implementation(CreateStrategy createStrategy,
                          FilterStrategy filterStrategy,
                          HasStrategy hasStrategy) {
        this.createStrategy = createStrategy;
        this.filterStrategy = filterStrategy;
        this.hasStrategy = hasStrategy;
    }

    public void createEntity(Object... values) {
        createStrategy.execute(values);
    }

    public boolean hasEntity(Object... values) {
        return hasStrategy.find(values);
    }

    public <T> ArrayList<T> filter(HashMap query) {
        return new ArrayList<>();
    }
}
