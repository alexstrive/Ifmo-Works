package io.github.novopashin.dao;

import io.github.novopashin.dao.impl.*;
import io.github.novopashin.dao.impl.bundles.ImplementationBundle;
import io.github.novopashin.dao.impl.bundles.ImplementationBundleCSV;
import io.github.novopashin.dao.schemes.Scheme;

import java.util.Optional;

public class DataAccessObject {
    private ImplementationBundle bundle;

    public DataAccessObject(String host, String login, String password) {
        // placeholder for sql bundle implementation
    }

    public DataAccessObject() {
        bundle = new ImplementationBundleCSV();
    }

    /**
     * Создание сущности по заданной схеме
     *
     * @param scheme
     */
    public void createEntity(Scheme scheme) {
        switch (scheme.getType()) {
            case STORE:
                this.createStoreEntity(scheme);
                break;
            case PRODUCT:
                this.createProductEntity(scheme);
                break;
        }
    }

    private void createStoreEntity(Scheme scheme) {
        getImplementationStore().create(scheme.getPayload());
    }

    private void createProductEntity(Scheme scheme) {
        this.getImplementationProduct().create(scheme.getPayload());
    }

    /**
     * Фильтрация сущностей по заданной схеме
     *
     * @param scheme
     */

    public Optional filterEntity(Scheme scheme) {
        switch (scheme.getType()) {
            case STORE:
                return filterStoreEntity(scheme);
            case PRODUCT:
                return filterProductEntity(scheme);
        }

        return Optional.empty();
    }

    private Optional filterStoreEntity(Scheme scheme) {
        return this.getImplementationStore().filter(scheme.getPayload());
    }

    private Optional filterProductEntity(Scheme scheme) {
        return this.getImplementationProduct().filter(scheme.getPayload());
    }

    private Implementation getImplementationStore() {
        return this.bundle.getImplementationStore();
    }

    private Implementation getImplementationProduct() {
        return this.bundle.getImplementationProduct();
    }
}
