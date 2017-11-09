#include <printf.h>
#include <stdlib.h>
#include "utils.h"

const int FREE_MINUTES = 499;

void getUsedMinutes(int *usedMinutes) {
    printf("Enter total minutes of calls: ");
    scanf("%d", usedMinutes);
}

void getSubscriptionFee(int *subscriptionFee) {
    printf("Enter subscription fee: ");
    scanf("%d", subscriptionFee);
}

void getCostOfMinute(int *costOfMinute) {
    printf("Enter price per minute over fee: ");
    scanf("%d", costOfMinute);
}

void getUserData(int *usedMinutes, int *subscriptionFee, int *costOfMinute) {
    getUsedMinutes(usedMinutes);
    getSubscriptionFee(subscriptionFee);
    getCostOfMinute(costOfMinute);
}

int isPrime(int targetNumber) {
    for (int currentNumber = 2; currentNumber < targetNumber; currentNumber++) {
        if (targetNumber % currentNumber == 0) {
            return 0;
        }
    }

    return 1;
}

int showPrimes(int targetNumber) {
    for (int currentNumber = 2; currentNumber <= targetNumber; ++currentNumber) {
        if (isPrime(currentNumber)) {
            printf("%d ", currentNumber);
        }
    }
}

// Variant 17
int main() {
    // Task 1
    showTaskTitle();

    int usedMinutes, subscriptionFee, costOfMinute;
    getUserData(&usedMinutes, &subscriptionFee, &costOfMinute);

    int deltaMinutes = FREE_MINUTES - usedMinutes;

    int totalPrice = (deltaMinutes >= 0)
                     ? subscriptionFee
                     : subscriptionFee + costOfMinute * abs(deltaMinutes);

    printf("\nTotal price for one month: %d \n\n", totalPrice);

    // Task 2
    showTaskTitle();

    int maxNumber;
    printf("Enter maximum number: ");
    scanf("%d", &maxNumber);

    showPrimes(maxNumber);

    return 0;
}