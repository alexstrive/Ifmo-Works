#ifndef WORKS_COORDINATE_H
#define WORKS_COORDINATE_H

struct Coordinate {
    int x;
    int y;
    int z;
};

void printCoordinate(struct Coordinate *coordinate) {
    printf("[%d, %d, %d]\n", coordinate->x, coordinate->y, coordinate->z);
}

void readCoordinate(struct Coordinate *coordinate) {
    scanf("%d %d %d", &coordinate->x, &coordinate->y, &coordinate->z);
}

#endif //WORKS_COORDINATE_H
