package io.github.novopashin.dao.schemes;

public class SchemeStore extends Scheme {
    public SchemeStore(String title) {
        super(SchemeType.STORE);
        set("title", title);
    }

    public SchemeStore(int code, String title) {
        this(title);
        set("code", code);
    }
}
