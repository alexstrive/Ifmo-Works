package io.github.novopashin.dao.strategies.custom.product;

import io.github.novopashin.Loader;

public class FilterProductCSV extends FilterProduct {

    public FilterProductCSV(Object targetObject) {
        super(targetObject);
    }

    @Override
    public boolean find(Object... values) {
        var products = Loader.getRecords(getFilename());
        return products.stream().anyMatch(product -> product.equals(values));
    }
}
