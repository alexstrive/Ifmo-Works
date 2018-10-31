#ifndef WORKS_PENTAGON_H
#define WORKS_PENTAGON_H

#include "vector.h"
#include <stdio.h>

struct Pentagon {
    struct Vector points[5];
};

void readCoordinates(struct Pentagon *pentagon);
float getPentagonPerimeter(struct Pentagon pentagon);
void createEmptyPentagon(struct Pentagon *pentagon);

#endif //WORKS_PENTAGON_H
