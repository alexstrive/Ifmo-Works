#include <stdio.h>
#include "utils.h"

void showNumberRepresentation(const int number, int base)
{
    switch (base)
    {
        case 8:
            printf("Octal number: %o\n", number);
            break;
        case 16:
            printf("Hexadecimal number: %x\n", number);
            break;
        default:
            printf("Decimal number: %d\n", number);
            break;
    }
}

// Variant - 9
int main()
{
    int firstNumber;
    int secondNumber;

    // Task 1
    showTaskTitle();
    printf("Enter first number (hexadecimal): ");
    scanf("%x", &firstNumber);

    // Task 2
    showTaskTitle();
    showNumberRepresentation(firstNumber, 8);

    // Task 3
    showTaskTitle();
    showNumberRepresentation(firstNumber, 8);
    showNumberRepresentation(firstNumber << 1, 8);

    // Task 4
    showTaskTitle();
    showNumberRepresentation(firstNumber, 8);
    showNumberRepresentation(~firstNumber, 8);

    // Task 5
    showTaskTitle();
    printf("Enter second number (octal): ");
    scanf("%o", &secondNumber);
    showNumberRepresentation(firstNumber & secondNumber, 8);

    return 0;
}