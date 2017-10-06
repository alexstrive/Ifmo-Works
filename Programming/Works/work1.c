#include <stdio.h>

void inputFloatNumber() {
    float floatNumber;

    printf("Enter a float number: ");
    scanf("%f", &floatNumber);
    printf("You entered: %f \n", floatNumber);
}

void inputIntNumber() {
    int intNumber;

    printf("Enter a int number: ");
    scanf("%i", &intNumber);
    printf("You entered: %i \n", intNumber);
}

int main() {
    inputFloatNumber();
    inputIntNumber();

    return 0;
}