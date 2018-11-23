package io.github.novopashin.dao;

import io.github.novopashin.MigrationType;
import io.github.novopashin.dao.impl.*;
import io.github.novopashin.dao.impl.bundles.*;
import io.github.novopashin.dao.schemes.Scheme;
import io.github.novopashin.dao.schemes.SchemeProduct;
import io.github.novopashin.dao.schemes.SchemeStore;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.Properties;

public class DataAccessObject {
    private Bundle bundle;
    private Properties properties;

    public DataAccessObject(Properties properties) {
        this.properties = properties;

        var type = properties.getProperty("type");
        var host = properties.getProperty("host");
        var login = properties.getProperty("login");
        var password = properties.getProperty("password");

        try {

            switch (type) {
                case "sql":
                    setImplementationBundleSQL();
                    break;

                case "csv":
                    setImplementationBundleCSV();
                    break;

                default:
                    throw new IllegalArgumentException("Incorrect property `type` value");
            }

        } catch (IllegalArgumentException e) {
            e.printStackTrace();
            throw new ExceptionInInitializerError("Failed to initialize a DataService");
        }
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

    /**
     * Обновление сущности по заданной схеме
     */
    public void update(Scheme scheme) throws Exception {
        switch (scheme.getType()) {
            case STORE:
                throw new Exception("Not yet supported Store operation");
            case PRODUCT:
                updateProductEntity(scheme);
                break;
        }
    }

    private void updateProductEntity(Scheme scheme) {
        this.getImplementationProduct().update(scheme.getPayload());
    }


    /**
     * Выполнение миграции
     * <p>
     * После завершения миграции операции выполняются над конечным пунктом миграции.
     *
     * @return
     */
    public void migrate(MigrationType migrationType) {
        switch (migrationType) {
            case CSV_TO_SQL:
                migrateFromCSVToSQL();
                break;
            case SQL_TO_CSV:
                migrateFromSQLToCSV();
                break;
        }

    }

    private void migrateFromCSVToSQL() {
        this.bundle = new MigrationBundleCSVToSQL(
                properties.getProperty("host"),
                properties.getProperty("login"),
                properties.getProperty("password")
        );

        commitMigration();

        setImplementationBundleSQL();
    }

    private void migrateFromSQLToCSV() {
        this.bundle = new MigrationBundleSQLToCSV(
                properties.getProperty("host"),
                properties.getProperty("login"),
                properties.getProperty("password")
        );

        commitMigration();

        setImplementationBundleCSV();
    }

    private void commitMigration() {
        var allSchemeStores = new SchemeStore();
        var allSchemeProducts = new SchemeProduct();

        var allStores = (ArrayList<Scheme>) filterEntity(allSchemeStores).get();
        var allProducts = (ArrayList<Scheme>) filterEntity(allSchemeProducts).get();

        allStores.forEach(this::createEntity);
        allProducts.forEach(this::createEntity);
    }

    // Below methods only for internal use

    private Implementation getImplementationStore() {
        return this.bundle.getImplementationStore();
    }

    private Implementation getImplementationProduct() {
        return this.bundle.getImplementationProduct();
    }

    private void setImplementationBundleSQL() {
        this.bundle = new ImplementationBundleSQL(properties.getProperty("host"),
                properties.getProperty("login"),
                properties.getProperty("password"));
    }

    private void setImplementationBundleCSV() {
        this.bundle = new ImplementationBundleCSV();
    }
}
