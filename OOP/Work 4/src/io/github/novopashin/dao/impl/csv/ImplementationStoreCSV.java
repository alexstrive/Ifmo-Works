package io.github.novopashin.dao.impl.csv;

import io.github.novopashin.dao.impl.Implementation;
import io.github.novopashin.dao.strategies.custom.store.CreateStoreCSV;
import io.github.novopashin.dao.strategies.custom.store.FilterStoreCSV;

public final class ImplementationStoreCSV extends Implementation {
    public ImplementationStoreCSV() {
        super(
                new CreateStoreCSV("stores.csv"),
                new FilterStoreCSV("stores.csv"),
                null
        );
    }
}
