package io.github.novopashin.dao.strategies.custom.product;

import io.github.novopashin.dao.strategies.custom.TargetConsumerSQL;
import io.github.novopashin.dao.strategies.general.CreateStrategy;

import java.util.Map;

public class CreateProductSQL extends TargetConsumerSQL implements CreateStrategy {
    public CreateProductSQL(String tablename, String host, String login, String password) {
        super(tablename, host, login, password);
    }

    @Override
    public void execute(Map payload) {
        var title = payload.get("title");
        var vendor = payload.get("vendor");
        var quantity = payload.get("quantity");
        var cost = payload.get("cost");
        System.out.println("insert into " + getTablename() + " values (\'" + title + "\', " + vendor + ", " + quantity + ", " + cost + ")");
        update("insert into " + getTablename() + " values (\'" + title + "\', " + vendor + ", " + quantity + ", " + cost + ")");
    }
}
