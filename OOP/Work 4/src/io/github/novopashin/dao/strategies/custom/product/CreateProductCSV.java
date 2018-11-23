package io.github.novopashin.dao.strategies.custom.product;

import io.github.novopashin.dao.strategies.custom.TargetConsumerCSV;
import io.github.novopashin.dao.strategies.general.CreateStrategy;

import java.util.HashMap;
import java.util.Map;

public class CreateProductCSV extends TargetConsumerCSV implements CreateStrategy {

    public CreateProductCSV(String filename) {
        super(filename);
    }

    @Override
    public void execute(Map payload) {
        var title = payload.get("title");
        var vendor = payload.get("vendor");
        var quantity = payload.get("quantity");
        var cost = payload.get("cost");

        writeCSV(title, vendor, quantity, cost);
    }
}
