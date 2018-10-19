#include <stdlib.h>
#include "Point.h"
#include "Set.h"

// Example of workflow
int main() {
    Point firstPoint = {15, 2};
    Point secondPoint = {0, 12};
    Point thirdPoint = {99, 11};

    Set set = createSet();

    push(&set, &firstPoint);
    push(&set, &secondPoint);
    push(&set, &thirdPoint);

    shift(&set);

    save(&set, "sample.txt");

    Set anotherSet = createSet();
    restore(&anotherSet, "sample.txt");

    Point fourthPoint = {256, 32};
    push(&anotherSet, &fourthPoint);

    return EXIT_SUCCESS;
}