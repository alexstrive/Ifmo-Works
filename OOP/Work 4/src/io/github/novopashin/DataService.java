package io.github.novopashin;

import io.github.novopashin.dao.DataAccessObject;
import io.github.novopashin.dao.schemes.Scheme;
import io.github.novopashin.dao.schemes.SchemeProduct;
import io.github.novopashin.dao.schemes.SchemeStore;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.Properties;

public class DataService {
    private DataAccessObject dataAccessObject;

    public DataService(Properties properties) {
        var type = properties.getProperty("type");
        var host = properties.getProperty("host");
        var login = properties.getProperty("login");
        var password = properties.getProperty("password");

        try {

            switch (type) {
                case "sql":
                    dataAccessObject = new DataAccessObject(host, login, password);
                    break;

                case "csv":
                    dataAccessObject = new DataAccessObject();
                    break;

                default:
                    throw new IllegalArgumentException("Incorrect property `type` value");
            }

        } catch (IllegalArgumentException e) {
            e.printStackTrace();
            throw new ExceptionInInitializerError("Failed to initialize a DataService");
        }
    }

    // Store
    public void createStore(String title) {
        var query = new SchemeStore(title);
        this.dataAccessObject.createEntity(query);
    }

    public boolean hasStore(String title) {
        var scheme = new SchemeStore(title);
        return this.dataAccessObject.filterEntity(scheme).isPresent();
    }


    // Product

    public void createProduct(String title, int code, int quantity, float cost) {
        var scheme = new SchemeProduct(title, code, quantity, cost);
        this.dataAccessObject.createEntity(scheme);
    }

    public boolean hasProduct(String title) {
        var scheme = new SchemeProduct(title);
        return this.dataAccessObject.filterEntity(scheme).isPresent();
    }

    public void putProducts() {
    }

    public String getMostCheapVendorOfProduct(String title) {
        var scheme = new SchemeProduct(title);
        var products = (ArrayList<Scheme>) this.dataAccessObject.filterEntity(scheme).get();

        return products.stream()
                .reduce((minimumScheme, currentScheme) -> {
                    var minimumCost = Float.valueOf(minimumScheme.getPayload().get("cost"));
                    var currentCost = Float.valueOf(currentScheme.getPayload().get("cost"));
                    return currentCost < minimumCost ? currentScheme : minimumScheme;
                })
                .get()
                .getPayload()
                .get("vendor");
    }

    public String getMostCheapVendorOfBatchProduct(String productTitle, int batchNumber) {
        return "NOT COMPLETED";
    }

    public Object determinePossiblePurchases(int upValue) {
        return null;
    }
}
