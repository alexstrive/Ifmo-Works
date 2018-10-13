package com.company;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.stream.Stream;

public class NumberList<T extends Number> {
    private ArrayList<T> list;
    private T maxRationalNumber, minRationalNumber;
    private HashMap<Double, Long> cache = new HashMap<>();

    public NumberList() {
        this.list = new ArrayList<>();
    }

    public NumberList(ArrayList<T> numbers) {
        this.list = numbers;
        prepareCache();
    }

    public void add(T... numbers) {
        list.addAll(Arrays.asList(numbers));
        prepareCache();
    }

    private void prepareCache() {
        cache.clear();
        assignNewMinAndMax();
    }

    private void assignNewMinAndMax() {
        initMinAndMaxIfNecessary();

        for (T currentRationalNumber : list) {
            if (currentRationalNumber.less(minRationalNumber)) {
                minRationalNumber = currentRationalNumber;
            }

            if (currentRationalNumber.greater(maxRationalNumber)) {
                maxRationalNumber = currentRationalNumber;
            }
        }
    }

    private void initMinAndMaxIfNecessary() {
        if (minRationalNumber == null || maxRationalNumber == null) {
            minRationalNumber = list.get(0);
            maxRationalNumber = list.get(0);
        }
    }

    public Long countGreaterThan(double targetValue) {
        if (!cache.containsKey(targetValue)) {
            var counted = list
                    .stream()
                    .filter(currentNumber -> currentNumber.greater(targetValue))
                    .count();

            cache.put(targetValue, counted);
        }

        return cache.get(targetValue);
    }

    public static <T extends Number>NumberList fromFile(String fileName, String delimiter) {
        Path filePath = Loader.getFilePath(fileName);

        var numberList = new NumberList<RationalNumber>();

        try (Stream<String> lines = Files.lines(filePath)) {
            lines.forEach(line -> {
                var values = Arrays.asList(line.split(delimiter));
                var numerator = Integer.parseInt(values.get(0));
                var denominator = Integer.parseInt(values.get(1));
                numberList.add(new RationalNumber(numerator, denominator));
            });
        } catch (IOException e) {
            e.printStackTrace();
        }

        return numberList;
    }

    public T getMaxRationalNumber() {
        return maxRationalNumber;
    }

    public T getMinRationalNumber() {
        return minRationalNumber;
    }

    public Stream stream() {
        return list.stream();
    }

    @Override
    public String toString() {
        return "NumberList {" +
                "\n\tlist: " + list +
                ",\n\tmaxRationalNumber: " + maxRationalNumber +
                ",\n\tminRationalNumber: " + minRationalNumber +
                ",\n\tcache: " + cache +
                "\n}";
    }
}
