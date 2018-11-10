package io.github.novopashin.dao.strategies.custom.store;

import io.github.novopashin.Loader;

public class HasStoreCSV extends HasStore {
    private final int STORE_TITLE_CSV_POSITION = 1;

    public HasStoreCSV(Object filename) {
        super(filename);
    }

    @Override
    public boolean find(Object... values) {
        var storeTitle = values[0];
        var stores = Loader.getRecords(getFilename());
        return stores.stream().anyMatch(record ->
                record.get(STORE_TITLE_CSV_POSITION).equals(storeTitle));
    }
}
