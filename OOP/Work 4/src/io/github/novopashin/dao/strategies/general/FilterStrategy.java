package io.github.novopashin.dao.strategies.general;

import io.github.novopashin.dao.schemes.Scheme;

import java.util.List;
import java.util.Map;
import java.util.Optional;

public interface FilterStrategy {
    Optional<List<Scheme>> filter(Map<String, String> payload);

    static boolean isMapValueEqual(Map<String, String> actual, Map<String, String> expected) {
        boolean isEqual = true;

        for (var key : expected.keySet()) {
            if (!actual.get(key).equals(expected.get(key))) {
                isEqual = false;
                break;
            }
        }

        return isEqual;
    }
}
