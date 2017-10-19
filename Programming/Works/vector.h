#ifndef WORKS_COORDINATE_H
#define WORKS_COORDINATE_H

#include <math.h>

struct Vector {
    int x;
    int y;
    int z;
};

struct Vector createVector(struct Vector startPoint, struct Vector endPoint) {
    struct Vector newVector = {0, 0, 0};

    newVector.x = endPoint.x - startPoint.x;
    newVector.y = endPoint.y - startPoint.y;
    newVector.z = endPoint.z - startPoint.z;

    return newVector;
}

void printVector(struct Vector coordinate) {
    printf("[%d, %d, %d]\n", coordinate.x, coordinate.y, coordinate.z);
}

void readVector(struct Vector *coordinate) {
    scanf("%d %d %d", &coordinate->x, &coordinate->y, &coordinate->z);
}

float getVectorLength(struct Vector vector) {
    return (float) sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}

#endif //WORKS_COORDINATE_H
