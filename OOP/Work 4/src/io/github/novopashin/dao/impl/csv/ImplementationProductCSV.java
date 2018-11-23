package io.github.novopashin.dao.impl.csv;

import io.github.novopashin.dao.impl.Implementation;
import io.github.novopashin.dao.strategies.custom.product.CreateProductCSV;
import io.github.novopashin.dao.strategies.custom.product.FilterProductCSV;
import io.github.novopashin.dao.strategies.custom.product.UpdateProductCSV;

public final class ImplementationProductCSV extends Implementation {
    public ImplementationProductCSV() {
        super(
                new CreateProductCSV("products.csv"),
                new FilterProductCSV("products.csv"),
                new UpdateProductCSV("products.csv")
        );
    }
}
