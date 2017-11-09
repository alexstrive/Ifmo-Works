#ifndef WORKS_COORDINATE_H
#define WORKS_COORDINATE_H

#include <stdio.h>
#include <math.h>

struct Vector {
    int x;
    int y;
    int z;
};

void createVector(struct Vector *targetVector, struct Vector startPoint, struct Vector endPoint);
void printVector(struct Vector coordinate);
void readVector(struct Vector *coordinate);
float getVectorLength(struct Vector vector);

#endif //WORKS_COORDINATE_H
