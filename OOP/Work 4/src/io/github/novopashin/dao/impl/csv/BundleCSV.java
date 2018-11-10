package io.github.novopashin.dao.impl.csv;

import io.github.novopashin.dao.impl.ImplementationBundle;
import io.github.novopashin.dao.impl.Implementation;

public class BundleCSV extends ImplementationBundle {
    public BundleCSV() {
        this.setImplementationProduct(new ImplementationProductCSV());
        this.setImplementationStore(new ImplementationStoreCSV());
    }
}
