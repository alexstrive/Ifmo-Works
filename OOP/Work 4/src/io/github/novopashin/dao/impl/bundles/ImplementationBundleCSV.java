package io.github.novopashin.dao.impl.bundles;

import io.github.novopashin.dao.impl.csv.ImplementationProductCSV;
import io.github.novopashin.dao.impl.csv.ImplementationStoreCSV;

public class ImplementationBundleCSV extends ImplementationBundle {
    public ImplementationBundleCSV() {
        this.setImplementationProduct(new ImplementationProductCSV());
        this.setImplementationStore(new ImplementationStoreCSV());
    }
}
