package io.github.novopashin.dao.strategies.custom.product;

import io.github.novopashin.dao.schemes.Scheme;
import io.github.novopashin.dao.schemes.SchemeType;
import io.github.novopashin.dao.strategies.custom.TargetConsumerCSV;
import io.github.novopashin.dao.strategies.general.FilterStrategy;

import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;

public class FilterProductCSV extends TargetConsumerCSV implements FilterStrategy {

    public FilterProductCSV(String filename) {
        super(filename, "title", "vendor", "quantity", "cost");
    }

    @Override
    public Optional<List<Scheme>> filter(Map<String, String> targetValues) {
        var basket = filteredStream(targetValues)
                .map(values -> new Scheme(SchemeType.PRODUCT, values))
                .collect(Collectors.toList());

        if (basket.isEmpty()) {
            return Optional.empty();
        }

        return Optional.of(basket);
    }
}
