package com.company;

public interface Number<T> {
    public abstract T value();

    public boolean greater(Number<T> anotherRationalNumber);

    public boolean greater(T targetValue);

    public boolean less(Number<T> anotherRationalNumber);

    public boolean less(T targetValue);
}
