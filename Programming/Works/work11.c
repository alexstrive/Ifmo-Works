#include "pentagon.h"

// Variant 17
int main() {
    struct Pentagon pentagon;
    createEmptyPentagon(&pentagon);
    readCoordinates(&pentagon);

    printf("\nPerimeter of pentagon is %f", getPentagonPerimeter(pentagon));

    return 0;
}