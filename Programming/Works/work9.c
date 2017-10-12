#include <math.h>
#include <printf.h>

int checkPrime(int number) {
    for (int currentNumber = 0; currentNumber < number / 2; ++currentNumber) {
        if (number % currentNumber) {
            return 0;
        }
    }

    return 1;
}

void showPrimes(int lastNumber) {
    for (int currentNumber = 2; currentNumber <= lastNumber; ++currentNumber) {
        if (checkPrime(currentNumber)) {
            printf("%d", currentNumber);
        }
    }
}

// Variant 17
int main() {
    const int freeMinutes = 499;

    // Task 1
    int totalMinutes;
    int basePrice;
    int pricePerMinute;

//    printf("Enter \n- Total minutes of calls\n- Price of plan\n- Price per minute of over limit: \n");
//    scanf("%d %d %d", &totalMinutes, &basePrice, &pricePerMinute);

    printf("Enter total minutes of calls: ");
    scanf("%d", &totalMinutes);

    printf("Enter price of plan: ");
    scanf("%d", &basePrice);

    int deltaMinutes = totalMinutes - 499;

    if (deltaMinutes > 0) {

    }

    // Task 2
    int number;
    scanf("%d", &number);

    for (int i = 1; i <= number; ++i) {
        printf("%d ", i);
    }

    return 0;
}