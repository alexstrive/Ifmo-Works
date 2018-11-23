package io.github.novopashin.dao.impl.bundles;

import io.github.novopashin.dao.impl.Implementation;
import io.github.novopashin.dao.strategies.custom.product.CreateProductCSV;
import io.github.novopashin.dao.strategies.custom.product.FilterProductSQL;
import io.github.novopashin.dao.strategies.custom.store.CreateStoreCSV;
import io.github.novopashin.dao.strategies.custom.store.FilterStoreSQL;

public class MigrationBundleSQLToCSV extends Bundle {
    public MigrationBundleSQLToCSV(String host, String login, String password) {

        // Stores
        this.setImplementationStore(
                new Implementation(
                        new CreateStoreCSV("stores.csv"),
                        new FilterStoreSQL("Stores", host, login, password),
                        null)
        );

        // Products
        this.setImplementationProduct(
                new Implementation(
                        new CreateProductCSV("products.csv"),
                        new FilterProductSQL("Products", host, login, password),
                        null
                )
        );
    }
}
