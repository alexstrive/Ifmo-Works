package io.github.novopashin.dao.strategies.custom.product;

import io.github.novopashin.dao.schemes.Scheme;
import io.github.novopashin.dao.schemes.SchemeProduct;
import io.github.novopashin.dao.schemes.SchemeStore;
import io.github.novopashin.dao.strategies.custom.TargetConsumerSQL;
import io.github.novopashin.dao.strategies.general.FilterStrategy;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Optional;

// Особая благодарность господам из Microsoft и Oracle за столь чудесный API
public class FilterProductSQL extends TargetConsumerSQL implements FilterStrategy {
    public FilterProductSQL(String tablename, String host, String login, String password) {
        super(tablename, host, login, password);
    }

    private String buildQuery(Map<String, String> payload) {
        var query = new StringBuilder("select * from Products");

        if (!payload.isEmpty()) {
            query.append(" where ");

            if (payload.containsKey("title")) {
                query.append("title = \'" + payload.get("title") + "\' ");
            }

            if (payload.containsKey("and vendor")) {
                query.append("vendor = " + payload.get("vendor") + " ");
            }

            if (payload.containsKey("quantity")) {
                query.append("quantity = " + payload.get("quantity") + " ");
            }

            if (payload.containsKey("cost")) {
                query.append("cost = " + payload.get("cost") + " ");
            }
        }

        return query.toString();
    }

    @Override
    public Optional<List<Scheme>> filter(Map<String, String> payload) {
        var resultSet = execute(buildQuery(payload));
        var basket = new ArrayList<Scheme>();

        try {
            while (resultSet.next()) {
                var title = resultSet.getString(1);
                var vendor = resultSet.getInt(2);
                var quantity = resultSet.getInt(3);
                var cost = resultSet.getFloat(4);

                basket.add(new SchemeProduct(title, vendor, quantity, cost));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        if (basket.isEmpty()) {
            return Optional.empty();
        }

        return Optional.of(basket);
    }
}
