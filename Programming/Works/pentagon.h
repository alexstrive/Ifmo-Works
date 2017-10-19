#ifndef WORKS_PENTAGON_H
#define WORKS_PENTAGON_H

#include <printf.h>
#include "coordinate.h"

struct Pentagon {
    // TODO: uglify names of coordinates
    struct Coordinate coordinates[5];
};

void readCoordinates(struct Pentagon *pentagon) {
    for (int number = 0; number < 5; number++) {
        printf("Enter coordinate [%d]: ", number + 1);
        readCoordinate(&pentagon->coordinates[number]);
    }
}

struct Pentagon createPentagon() {
    struct Pentagon newTriangle = {};
    return newTriangle;
}

#endif //WORKS_PENTAGON_H
