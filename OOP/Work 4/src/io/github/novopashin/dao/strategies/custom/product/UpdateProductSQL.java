package io.github.novopashin.dao.strategies.custom.product;

import io.github.novopashin.dao.strategies.custom.TargetConsumer;
import io.github.novopashin.dao.strategies.custom.TargetConsumerSQL;
import io.github.novopashin.dao.strategies.general.UpdateStrategy;

import java.util.Map;

public class UpdateProductSQL extends TargetConsumerSQL implements UpdateStrategy {

    public UpdateProductSQL(String tablename, String host, String login, String password) {
        super(tablename, host, login, password);
    }

    private String buildQuery(Map payload) {
        var query = new StringBuilder("update Products");

        if (!payload.isEmpty()) {
            query.append(" set ");

            if (payload.containsKey("title")) {
                query.append("title = \'" + payload.get("title") + "\' ");
            }

            if (payload.containsKey("vendor")) {
                query.append(", vendor = " + payload.get("vendor") + " ");
            }

            if (payload.containsKey("quantity")) {
                query.append(", quantity = " + payload.get("quantity") + " ");
            }

            if (payload.containsKey("cost")) {
                query.append(", cost = " + payload.get("cost") + " ");
            }
        }

        query
                .append("where title = \'")
                .append(payload.get("title"))
                .append("\'");


        System.out.println(query);
        return query.toString();
    }

    @Override
    public void update(Map payload) {
        var updateQuery = buildQuery(payload);
        super.update(updateQuery);
    }
}
