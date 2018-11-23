package io.github.novopashin.dao.impl.bundles;

import io.github.novopashin.dao.impl.sql.ImplementationProductSQL;
import io.github.novopashin.dao.impl.sql.ImplementationStoreSQL;

public class ImplementationBundleSQL extends Bundle {
    public ImplementationBundleSQL(String host, String login, String password) {
        this.setImplementationStore(new ImplementationStoreSQL(host, login, password));
        this.setImplementationProduct(new ImplementationProductSQL(host, login, password));
    }
}
