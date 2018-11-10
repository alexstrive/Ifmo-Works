package io.github.novopashin.dao.impl;

public abstract class ImplementationBundle {
    private Implementation implementationStore, implementationProduct;

    protected Implementation getImplementationStore() {
        return implementationStore;
    }

    protected Implementation getImplementationProduct() {
        return implementationProduct;
    }

    protected void setImplementationStore(Implementation implementationStore) {
        this.implementationStore = implementationStore;
    }

    protected void setImplementationProduct(Implementation implementationProduct) {
        this.implementationProduct = implementationProduct;
    }
}
