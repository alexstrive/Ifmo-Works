#include <printf.h>
#include <string.h>

void showTitle(const int task_number) {
    printf("--- Task %d ---\n", task_number);
}

void compareTwoStrings(const char *firstString, const char *lastString) {
    int resultComparing = strcmp(firstString, lastString);

    if (resultComparing == 0) {
        printf("[%s] equals [%s]\n", firstString, lastString);
    }
    else if (resultComparing < 0) {
        printf("[%s] precedes [%s]\n", firstString, lastString);
    }
    else if (resultComparing > 0) {
        printf("[%s] follows [%s]\n", firstString, lastString);
    }
}

void compareSymbolsTwoStrings(const char *firstString, const char *lastString, int numberSymbols) {
    int resultComparing = strncmp(firstString, lastString, numberSymbols)
}

// Variant 17
int main() {
    char *phrase = "Hello world";
    char *firstPart = "Hello";
    char *secondPart = "world";

    // Task 1 (3)
    compareTwoStrings(phrase, firstPart);

    // Task 2 (4)
    compareSymbolsTwoStrings(phrase, firstPart, 4);

    // Task 3 (7)
    // Task 4 (10)
    // Task 5 (13)

    return 0;
}