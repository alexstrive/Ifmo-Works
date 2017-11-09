#include <stdio.h>
#include <stdlib.h>

int addNumbers(int a, int b) {
    return a + b;
}

// Variant 19
int main(int argCount, char *argv[]) {
    freopen("../output.txt", "w", stdout);

    int firstNumber = atoi(argv[1]);
    int secondNumber = atoi(argv[2]);
    int sumNumber = addNumbers(firstNumber, secondNumber);

    printf("%d + %d = %d", firstNumber, secondNumber, sumNumber);

    return 0;
}

