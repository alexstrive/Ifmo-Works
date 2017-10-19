#include "pentagon.h"

// Variant 17
int main() {
    struct Pentagon pentagon = createEmptyPentagon();
    readCoordinates(&pentagon);

    printf("\nPerimeter of pentagon is %d", getPentagonPerimeter(pentagon));

    return 0;
}