package io.github.novopashin.dao.strategies.custom.store;

import io.github.novopashin.dao.schemes.Scheme;
import io.github.novopashin.dao.schemes.SchemeType;
import io.github.novopashin.dao.strategies.custom.TargetConsumerCSV;
import io.github.novopashin.dao.strategies.general.FilterStrategy;

import java.util.HashMap;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

public class FilterStoreCSV extends TargetConsumerCSV implements FilterStrategy {

    public FilterStoreCSV(String filename) {
        super(filename, "code", "title");
    }

    @Override
    public Optional<List<Scheme>> filter(HashMap<String, String> targetValues) {
        var basket = filteredStream(targetValues)
                .map(values -> new Scheme(SchemeType.STORE, values))
                .collect(Collectors.toList());

        if (basket.isEmpty()) {
            return Optional.empty();
        }

        return Optional.of(basket);
    }
}