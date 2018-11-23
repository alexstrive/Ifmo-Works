package io.github.novopashin.dao.impl.bundles;

import io.github.novopashin.dao.impl.Implementation;
import io.github.novopashin.dao.strategies.custom.product.CreateProductSQL;
import io.github.novopashin.dao.strategies.custom.product.FilterProductCSV;
import io.github.novopashin.dao.strategies.custom.store.CreateStoreSQL;
import io.github.novopashin.dao.strategies.custom.store.FilterStoreCSV;

public class MigrationBundleCSVToSQL extends Bundle {
    public MigrationBundleCSVToSQL(String host, String login, String password) {
        this.setImplementationStore(
                new Implementation(
                        new CreateStoreSQL("Stores", host, login, password),
                        new FilterStoreCSV("stores.csv"),
                        null)
        );

        this.setImplementationProduct(
                new Implementation(
                        new CreateProductSQL("Products", host, login, password),
                        new FilterProductCSV("products.csv"),
                        null)
        );
    }
}
