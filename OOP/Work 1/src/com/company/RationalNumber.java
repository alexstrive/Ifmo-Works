package com.company;


public class RationalNumber implements Number<Double> {
    private int numerator, denominator;

    public RationalNumber(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
    }

    public Double value() {
        return (double) numerator / denominator;
    }

    @Override
    public boolean greater(Number<Double> anotherRationalNumber) {
        return this.value() > anotherRationalNumber.value();
    }

    @Override
    public boolean greater(Double targetValue) {
        return this.value() > targetValue;
    }

    @Override
    public boolean less(Number<Double> anotherRationalNumber) {
        return this.value() < anotherRationalNumber.value();
    }

    @Override
    public boolean less(Double targetValue) {
        return this.value() < targetValue;
    }
}
