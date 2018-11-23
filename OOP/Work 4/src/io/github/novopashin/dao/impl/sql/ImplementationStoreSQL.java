package io.github.novopashin.dao.impl.sql;

import io.github.novopashin.dao.impl.Implementation;
import io.github.novopashin.dao.strategies.custom.store.CreateStoreSQL;
import io.github.novopashin.dao.strategies.custom.store.FilterStoreSQL;

public class ImplementationStoreSQL extends Implementation {
    public ImplementationStoreSQL(String host, String login, String password) {
        super(
                new CreateStoreSQL("Stores", host, login, password),
                new FilterStoreSQL("Stores", host, login, password),
                null
        );
    }
}
