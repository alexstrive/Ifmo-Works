package io.github.novopashin.dao.impl;

import io.github.novopashin.dao.strategies.general.CreateStrategy;
import io.github.novopashin.dao.strategies.general.FilterStrategy;
import io.github.novopashin.dao.strategies.general.UpdateStrategy;

import java.util.Map;
import java.util.Optional;

public class Implementation {
    private CreateStrategy createStrategy;
    private FilterStrategy filterStrategy;
    private UpdateStrategy updateStrategy;

    public Implementation(CreateStrategy createStrategy, FilterStrategy filterStrategy, UpdateStrategy updateStrategy) {
        this.createStrategy = createStrategy;
        this.filterStrategy = filterStrategy;
        this.updateStrategy = updateStrategy;
    }

    public void create(Map payload) {
        createStrategy.execute(payload);
    }

    public void update(Map payload) {
        updateStrategy.update(payload);
    }

    public Optional filter(Map payload) {
        return filterStrategy.filter(payload);
    }
}
