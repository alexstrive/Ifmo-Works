package io.github.novopashin.dao.schemes;

public class SchemeStore extends Scheme {
    public SchemeStore() {
        super(SchemeType.STORE);
    }

    public SchemeStore(String title) {
        this();
        set("title", title);
    }

    public SchemeStore(int code, String title) {
        this(title);
        set("code", code);
    }
}
