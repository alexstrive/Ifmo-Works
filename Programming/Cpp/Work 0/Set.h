#ifndef WORK_SET_H
#define WORK_SET_H

#include <stdio.h>
#include "Point.h"

typedef struct {
    struct PointNode *head;
    int length;
} Set;

struct PointNode {
    Point *value;
    struct PointNode *next;
};

int push(Set *set, Point *point);

int shift(Set *set);

int save(Set *set, char *filename);

int restore(Set *set, char *filename);

Set createSet();

#endif //WORK_SET_H