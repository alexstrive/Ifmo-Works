package io.github.novopashin.dao.strategies.custom.store;

import io.github.novopashin.dao.schemes.Scheme;
import io.github.novopashin.dao.schemes.SchemeStore;
import io.github.novopashin.dao.strategies.custom.TargetConsumerSQL;
import io.github.novopashin.dao.strategies.general.FilterStrategy;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Optional;

// Особая благодарность господам из Microsoft и Oracle за столь чудесный API
public class FilterStoreSQL extends TargetConsumerSQL implements FilterStrategy {
    public FilterStoreSQL(String tablename, String host, String login, String password) {
        super(tablename, host, login, password);
    }

    private String buildQuery(Map<String, String> payload) {
        var query = new StringBuilder("select * from Stores");

        if (!payload.isEmpty()) {
            query.append(" where ");

            if (payload.containsKey("code")) {
                query.append("code = " + payload.get("code") + " ");
            }

            if (payload.containsKey("title")) {
                query.append("title = \'" + payload.get("title") + "\' ");
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
                var code = resultSet.getInt(1);
                var title = resultSet.getString(2);
                basket.add(new SchemeStore(code, title));
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
