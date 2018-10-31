#include "pentagon.h"

void readCoordinates(struct Pentagon *pentagon) {
    for (int number = 0; number < 5; number++) {
        printf("Enter point coordinate [%d]: ", number + 1);
        readVector(&pentagon->points[number]);
    }
}

float getPentagonPerimeter(struct Pentagon pentagon) {
    float perimeter = 0;

    for (int i = 0; i < 5; ++i) {

        int startPointIndex = i;
        // if start point is last then connect it with first point
        int endPointIndex = i == 4 ? 0 : i + 1;

        struct Vector line;
        createVector(
                &line,
                pentagon.points[startPointIndex],
                pentagon.points[endPointIndex]
        );

        perimeter += getVectorLength(line);
    }

    return perimeter;
}

void createEmptyPentagon(struct Pentagon *pentagon) {
    struct Pentagon newPentagon = {0, 0, 0, 0};
    *pentagon = newPentagon;
}