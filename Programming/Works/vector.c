#include "vector.h"


void readVector(struct Vector *coordinate) {
    scanf("%d %d %d", &coordinate->x, &coordinate->y, &coordinate->z);
}

void printVector(struct Vector coordinate) {
    printf("[%d, %d, %d]\n", coordinate.x, coordinate.y, coordinate.z);
}

float getVectorLength(struct Vector vector) {
    return (float) sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}

void createVector(struct Vector *targetVector, struct Vector startPoint, struct Vector endPoint) {
    struct Vector newVector = {0, 0, 0};

    newVector.x = endPoint.x - startPoint.x;
    newVector.y = endPoint.y - startPoint.y;
    newVector.z = endPoint.z - startPoint.z;

    *targetVector = newVector;
}
