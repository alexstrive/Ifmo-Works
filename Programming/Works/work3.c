#include <stdio.h>

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

void showTitle(const int taskNumber) {
    printf("\n--- Task %d ---\n", taskNumber);
}

// Variant - 9
int main()
{
    int numberFirst;
    int numberSecond;

    // Task 1
    showTitle(1);
    printf("Enter first number (hexadecimal): ");
    scanf("%x", &numberFirst);

    // Task 2
    showTitle(2);
    showNumberRepresentation(numberFirst, 8);

    // Task 3
    showTitle(3);
    showNumberRepresentation(numberFirst, 8);
    showNumberRepresentation(numberFirst << 1, 8);

    // Task 4
    showTitle(4);
    showNumberRepresentation(numberFirst, 8);
    showNumberRepresentation(~numberFirst, 8);

    // Task 5
    showTitle(5);
    printf("Enter second number (octal): ");
    scanf("%o", &numberSecond);
    showNumberRepresentation(numberFirst & numberSecond, 8);

    return 0;
}