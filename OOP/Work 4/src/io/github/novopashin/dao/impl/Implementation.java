package io.github.novopashin.dao.impl;

import io.github.novopashin.dao.strategies.general.CreateStrategy;
import io.github.novopashin.dao.strategies.general.FilterStrategy;

import java.util.HashMap;
import java.util.Optional;

public abstract class Implementation {
    private CreateStrategy createStrategy;
    private FilterStrategy filterStrategy;

    public Implementation(CreateStrategy createStrategy, FilterStrategy filterStrategy) {
        this.createStrategy = createStrategy;
        this.filterStrategy = filterStrategy;
    }

    public void create(HashMap payload) {
        createStrategy.execute(payload);
    }

    public Optional filter(HashMap query) {
        return filterStrategy.filter(query);
    }
}
