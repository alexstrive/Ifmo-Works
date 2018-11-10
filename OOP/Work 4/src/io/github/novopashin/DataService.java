package io.github.novopashin;

import io.github.novopashin.dao.DataAccessObject;

import java.sql.SQLException;
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

        } catch (IllegalArgumentException | SQLException | ClassNotFoundException e) {
            e.printStackTrace();
            throw new ExceptionInInitializerError("Failed to initialize a DataService");
        }
    }

    public void createStore(String title) {
        this.dataAccessObject.createStoreEntity(title);
    }

    public boolean hasStore(String storeTitle) {
        return this.dataAccessObject.hasStoreEntity(storeTitle);
    }

    public Object filter() { return null; }

    public void putProducts() {}

    public String getMostCheapVendorOfProduct(String productTitle) {
        return "NOT COMPLETED";
    }

    public String getMostCheapVendorOfBatchProduct(String productTitle, int batchNumber) {
        return "NOT COMPLETED";
    }

    public Object determinePossiblePurchases(int upValue) {
        return null;
    }
}
