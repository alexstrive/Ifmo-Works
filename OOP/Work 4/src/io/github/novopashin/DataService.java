package io.github.novopashin;

import io.github.novopashin.dao.DataAccessObject;
import io.github.novopashin.dao.MigrationType;
import io.github.novopashin.dao.schemes.Scheme;
import io.github.novopashin.dao.schemes.SchemeProduct;
import io.github.novopashin.dao.schemes.SchemeStore;

import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class DataService {
    private DataAccessObject dataAccessObject;

    public DataService(Properties properties) {
        this.dataAccessObject = new DataAccessObject(properties);
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

    public void shipProducts(String title, int vendor, int newQuantity, float newPrice) {
        var scheme = new SchemeProduct(title, vendor, newQuantity, newPrice);

        try {
            this.dataAccessObject.update(scheme);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // TODO: check for null value
    public List getMostCheapVendorOfProduct(String title) {
        var scheme = new SchemeProduct(title);
        var products = (ArrayList<Scheme>) this.dataAccessObject.filterEntity(scheme).get();

        var mostCheapProductBatch = products.stream().reduce((minimumScheme, currentScheme) -> {
            var minimumCost = Float.valueOf(minimumScheme.getPayload().get("cost"));
            var currentCost = Float.valueOf(currentScheme.getPayload().get("cost"));
            return currentCost < minimumCost ? currentScheme : minimumScheme;
        }).get();

        var mostCheapCost = mostCheapProductBatch.getPayload().get("cost");

        return products.stream()
                .filter(product -> product.getPayload().get("cost").equals(mostCheapCost))
                .map(product -> product.getPayload().get("vendor"))
                .collect(Collectors.toList());
    }

    protected Optional filterProduct() {
        var scheme = new SchemeProduct();
        return this.dataAccessObject.filterEntity(scheme);
    }

    protected Optional filterProduct(String title) {
        var scheme = new SchemeProduct(title);
        return this.dataAccessObject.filterEntity(scheme);
    }

    protected Optional filterProduct(String title, int vendor) {
        var scheme = new SchemeProduct(title, vendor);
        return this.dataAccessObject.filterEntity(scheme);
    }

    public HashMap<String, Integer> whichProductsPossibleBuy(float price) {
        var products = (ArrayList) filterProduct().get();
        var results = new HashMap<String, Integer>();

        products.stream().forEach(product -> {
            var productScheme = (Scheme) product;
            var cost = Float.valueOf(productScheme.getPayload().get("cost"));
            var title = productScheme.getPayload().get("title");
            var quantity = Integer.valueOf(productScheme.getPayload().get("quantity"));

            var possible = (int) Math.floor(price / cost);

            if (possible <= quantity && possible != 0) {
                results.put(title, possible);
            }
        });

        return results;
    }

    public float cheapBatchProductCost(String title, int batchSize) {
        var avaliableProducts = (ArrayList<Scheme>) filterProduct(title).get();
        var totalCost = Float.parseFloat(avaliableProducts.get(0).getPayload().get("cost")) * batchSize;

        for (var product : avaliableProducts) {
            var currentCost = Float.parseFloat(product.getPayload().get("cost"));
            var currentQuantity = Integer.parseInt(product.getPayload().get("quantity"));

            if (currentQuantity > batchSize) {
                var currentBatchCost = batchSize * currentCost;
                if (currentBatchCost < totalCost) {
                    totalCost = batchSize * currentCost;
                }
            }
        }

        return totalCost;
    }

    public float buy(String title, int batchSize) {
        var avaliableProducts = (ArrayList<Scheme>) filterProduct(title).get();
        var totalCost = Float.parseFloat(avaliableProducts.get(0).getPayload().get("cost")) * batchSize;

        for (var product : avaliableProducts) {
            var currentCost = Float.parseFloat(product.getPayload().get("cost"));
            var currentVendor = Integer.parseInt(product.getPayload().get("vendor"));
            var currentQuantity = Integer.parseInt(product.getPayload().get("quantity"));

            if (currentQuantity > batchSize) {
                var scheme = new SchemeProduct(title, currentVendor, currentQuantity - batchSize, currentCost);

                try {
                    this.dataAccessObject.update(scheme);
                } catch (Exception e) {
                    e.printStackTrace();
                }

                break;
            }
        }

        return totalCost;
    }

    public void migrate(MigrationType migrationType) {
        this.dataAccessObject.migrate(migrationType);
    }
}
