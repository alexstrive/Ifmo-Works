package io.github.novopashin.dao.schemes;

import java.util.HashMap;
import java.util.Map;

public class Scheme {
    private SchemeType type;
    private Map<String, String> payload = new HashMap<>();

    public Scheme(SchemeType type) {
        this.type = type;
    }

    public Scheme(SchemeType type, Map<String, String> payload) {
        this.type = type;
        this.payload = payload;
    }

    public SchemeType getType() {
        return type;
    }

    protected void set(String key, String value) {
        payload.put(key, value);
    }

    protected void set(String key, int value) {
        set(key, String.valueOf(value));
    }

    protected void set(String key, float value) {
        set(key, String.valueOf(value));
    }

    protected void set(Object key, Object value) {
        set(key.toString(), value.toString());
    }

    public void update(HashMap newPayload) {
        for (var key : newPayload.keySet()) {
            set(key, newPayload.get(key));
        }

    }

    public HashMap<String, String> getPayload() {
        return new HashMap<>(payload);
    }
}
