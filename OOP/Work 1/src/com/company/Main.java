package com.company;

public class Main {
    public static void main(String[] args) {
        var numberList = new NumberList<>();

        var fractionOne = new RationalNumber(1, 2);
        var fractionTwo = new RationalNumber(5, 2);
        var fractionThree = new RationalNumber(10, 2);

        numberList.add(fractionOne, fractionTwo, fractionThree);

        System.out.println(numberList.countGreaterThan(2));

        var numberListFromFile = NumberList.fromFile("example.nums", "/");

        var polynominal = new Polynomial(numberListFromFile);
        System.out.println(polynominal.value(13));
    }
}
