package io.github.novopashin.dao.strategies.custom.store;

import io.github.novopashin.Loader;
import io.github.novopashin.dao.strategies.custom.TargetConsumerCSV;
import io.github.novopashin.dao.strategies.general.CreateStrategy;

import java.util.HashMap;

public class CreateStoreCSV extends TargetConsumerCSV implements CreateStrategy {

    public CreateStoreCSV(String filename) {
        super(filename);
    }

    private int getFreeCodeVendor() {
        return Loader.getRecords(getTargetObject().toString()).size() + 2;
    }

    @Override
    public void execute(HashMap payload) {
        var code = getFreeCodeVendor();
        var title = payload.get("title");

        writeCSV(code, title);
    }
}
