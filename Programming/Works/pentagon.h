#ifndef WORKS_PENTAGON_H
#define WORKS_PENTAGON_H

#include <printf.h>
#include "vector.h"

struct Pentagon {
    struct Vector points[5];
};

void readCoordinates(struct Pentagon *pentagon) {
    for (int number = 0; number < 5; number++) {
        printf("Enter point coordinate [%d]: ", number + 1);
        readVector(&pentagon->points[number]);
    }
}

int getPentagonPerimeter(struct Pentagon pentagon) {
    int perimeter = 0;

    for (int i = 0; i < 5; ++i) {

        int startPointIndex = i;
        // if start point is last then connect it with first point
        int endPointIndex = i == 4 ? 0 : i + 1;

        struct Vector line = createVector(
                pentagon.points[startPointIndex],
                pentagon.points[endPointIndex]
        );

        perimeter += getVectorLength(line);
    }

    return perimeter;
}

struct Pentagon createEmptyPentagon() {
    struct Pentagon newPentagon = {0, 0, 0, 0};
    return newPentagon;
}

#endif //WORKS_PENTAGON_H
