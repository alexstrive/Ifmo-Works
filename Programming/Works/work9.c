#include <printf.h>
#include <stdlib.h>
#include "utils.h"

const int FREE_MINUTES = 499;

void getTotalMinutes(int *totalMinutes) {
    printf("Enter total minutes of calls: ");
    scanf("%d", totalMinutes);
}

void getSubscriptionFee(int *subscriptionFee) {
    printf("Enter subscription fee: ");
    scanf("%d", subscriptionFee);
}

void getCostOfMinute(int *storage) {
    printf("Enter price per minute over fee: ");
    scanf("%d", storage);
}

void getUserData(int *totalMinutes, int *subscriptionFee, int *pricePerMinute) {
    getTotalMinutes(totalMinutes);
    getSubscriptionFee(subscriptionFee);
    getCostOfMinute(pricePerMinute);
}

// Variant 17
int main() {
    // Task 1
    showTaskTitle();

    int totalMinutes, subscriptionFee, costOfMinute;
    getUserData(&totalMinutes, &subscriptionFee, &costOfMinute);

    int deltaMinutes = FREE_MINUTES - totalMinutes;

    int totalPrice = (deltaMinutes >= 0)
                     ? subscriptionFee
                     : subscriptionFee + costOfMinute * abs(deltaMinutes);

    printf("Total price for one month: %d \n\n", totalPrice);

    // Task 2
    showTaskTitle();

    return 0;
}