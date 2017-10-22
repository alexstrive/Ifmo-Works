#include <stdio.h>
#include "utils.h"

int sumDigits(int number) {
    if (number < 10) {
        return number;
    }
    else {
        return number % 10 + sumDigits(number / 10);
    }
}

int gcd(int a, int b) {
    int c;

    while (a) {
        c = a;
        a = b % a;
        b = c;
    }

    return b;
}

int lcm(int a, int b) {
    return a * (b / gcd(a, b));
}

// Variant 19
int main() {
    // Task 1
    showTaskTitle();
    int firstNumber, secondNumber;

    printf("Enter first number value: ");
    scanf("%d", &firstNumber);

    printf("Enter second number value: ");
    scanf("%d", &secondNumber);

    printf("\nGCD: %d", gcd(firstNumber, secondNumber));
    printf("\nLCM: %d\n\n", lcm(firstNumber, secondNumber));

    // Task 2
    showTaskTitle();

    int number;
    printf("Enter a number value: ");
    scanf("%d", &number);

    printf("\nSum of digits: %d", sumDigits(number));

    return 0;
}