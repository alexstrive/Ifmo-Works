package io.github.novopashin.dao.strategies.custom.product;

import io.github.novopashin.dao.strategies.custom.TargetConsumerCSV;
import io.github.novopashin.dao.strategies.general.UpdateStrategy;

import java.util.Map;

public class UpdateProductCSV extends TargetConsumerCSV implements UpdateStrategy {
    public UpdateProductCSV(String filename) {
        super(filename, "title", "vendor", "quantity", "cost");
    }

    @Override
    public void update(Map payload) {
        var createStrategy = new CreateProductCSV(getFilename());
        createStrategy.execute(payload);
    }
}