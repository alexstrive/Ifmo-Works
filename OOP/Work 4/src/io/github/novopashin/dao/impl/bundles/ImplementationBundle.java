package io.github.novopashin.dao.impl.bundles;

import io.github.novopashin.dao.impl.Implementation;

public abstract class ImplementationBundle {
    private Implementation implementationStore, implementationProduct;

    public Implementation getImplementationStore() {
        return implementationStore;
    }

    public Implementation getImplementationProduct() {
        return implementationProduct;
    }

    protected void setImplementationStore(Implementation implementationStore) {
        this.implementationStore = implementationStore;
    }

    protected void setImplementationProduct(Implementation implementationProduct) {
        this.implementationProduct = implementationProduct;
    }
}
