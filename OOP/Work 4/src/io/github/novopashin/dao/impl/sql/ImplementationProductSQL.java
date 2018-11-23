package io.github.novopashin.dao.impl.sql;

import io.github.novopashin.dao.impl.Implementation;
import io.github.novopashin.dao.strategies.custom.product.CreateProductSQL;
import io.github.novopashin.dao.strategies.custom.product.FilterProductSQL;
import io.github.novopashin.dao.strategies.custom.product.UpdateProductSQL;
import io.github.novopashin.dao.strategies.custom.store.CreateStoreSQL;
import io.github.novopashin.dao.strategies.custom.store.FilterStoreSQL;

public class ImplementationProductSQL extends Implementation {
    public ImplementationProductSQL(String host, String login, String password) {
        super(
                new CreateProductSQL("Products", host, login, password),
                new FilterProductSQL("Products", host, login, password),
                new UpdateProductSQL("Products", host, login, password)
        );
    }
}
