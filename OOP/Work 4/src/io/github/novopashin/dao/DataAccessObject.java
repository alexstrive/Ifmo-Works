package io.github.novopashin.dao;

import io.github.novopashin.dao.impl.*;
import io.github.novopashin.dao.impl.csv.BundleCSV;

import java.sql.SQLException;

public class DataAccessObject {
    private ImplementationBundle bundle;

    public DataAccessObject(String host, String login, String password) throws SQLException, ClassNotFoundException {
//        bundle = new ImplementationStoresSQL(host, login, password);
    }

    public DataAccessObject() {
        bundle = new BundleCSV();
    }

    public void createProductEntity(Object ...values) {
        this.getImplementationProduct().createEntity(values);
    }

    public void createStoreEntity(String title) {
        getImplementationStore().createEntity(title);
    }


    public boolean hasStoreEntity(String entityTitle) {
        return this.bundle.getImplementationStore().hasEntity(entityTitle);
    }

    public boolean hasProductEntity(String entityTitle) {
        return this.bundle.getImplementationProduct().hasEntity();
    }

    private Implementation getImplementationStore() {
        return this.bundle.getImplementationStore();
    }
    private Implementation getImplementationProduct() {
        return this.bundle.getImplementationProduct();
    }
}
