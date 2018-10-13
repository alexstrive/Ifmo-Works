package com.company;

import java.util.ArrayList;
import java.util.stream.Collectors;

public class Polynomial {
    private NumberList coefficients;

    public Polynomial(NumberList coefficients) {
        this.coefficients = coefficients;
    }

    public double value(int x) {
        var coefficientValues = getCoefficientValues();

        double result = 0;
        for (int i = 0; i < coefficientValues.size(); i++) {
            result += coefficientValues.get(i) * Math.pow(x, i);
        }

        return result;
    }

    private ArrayList<Double> getCoefficientValues() {
        return (ArrayList<Double>) this.coefficients
                .stream()
                .map(coefficient -> ((RationalNumber) coefficient).value())
                .collect(Collectors.toList());
    }
}
