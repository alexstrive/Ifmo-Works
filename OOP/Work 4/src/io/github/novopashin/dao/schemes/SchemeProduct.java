package io.github.novopashin.dao.schemes;

public class SchemeProduct extends Scheme {
    public SchemeProduct() {
        super(SchemeType.PRODUCT);
    }

    public SchemeProduct(String title) {
        this();
        set("title", title);
    }

    public SchemeProduct(String title, int vendor) {
        this(title);
        set("vendor", vendor);
    }

    public SchemeProduct(String title, int vendor, int quantity) {
        this(title, vendor);
        set("quantity", quantity);
    }

    public SchemeProduct(String title, int vendor, int quantity, float cost) {
        this(title, vendor, quantity);
        set("cost", cost);
    }
}
