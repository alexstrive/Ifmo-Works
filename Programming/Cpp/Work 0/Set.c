#include <stddef.h>
#include <stdlib.h>
#include "Set.h"

int push(Set *set, Point *point) {
    // TODO: Extract creating of new Node in method
    struct PointNode *newNode = (struct PointNode *) malloc(sizeof(struct PointNode));
    newNode->value = point;
    newNode->next = NULL;

    // Case 1
    // Attach to head if no elements

    if (set->head == NULL) {
        set->head = newNode;
        set->length++;
        return EXIT_SUCCESS;
    }

    // Case 2
    // Attach to tail if elements presents

    struct PointNode *currentNode = set->head;

    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    set->length++;

    return EXIT_SUCCESS;
}

int shift(Set *set) {
    struct PointNode *currentNode = set->head;

    while (currentNode->next->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = NULL;
    set->length--;

    return EXIT_SUCCESS;
}

int saveNode(FILE *file, struct PointNode *node) {
    fprintf(file, "%d\n%d\n", node->value->x, node->value->y);
    return EXIT_SUCCESS;
}

int save(Set *set, char *filename) {
    FILE *file = fopen(filename, "w");
    struct PointNode *currentNode = set->head;

    while (currentNode->next != NULL) {
        saveNode(file, currentNode);
        currentNode = currentNode->next;
    }

    saveNode(file, currentNode);

    fclose(file);

    return EXIT_SUCCESS;
}

int restore(Set *set, char *filename) {
    FILE *file = fopen(filename, "r");

    int x, y;
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, file) != -1) {
        int x = atoi(line);
        getline(&line, &len, file);
        int y = atoi(line);

        Point *newPoint = (Point *) malloc(sizeof(Point));
        newPoint->x = x;
        newPoint->y = y;
        push(set, newPoint);
    }

    fclose(file);

    return EXIT_SUCCESS;
}

int emptySet(Set *set) {
    set->head = NULL;
    set->length = 0;

    return EXIT_SUCCESS;
}

Set createSet() {
    Set set;
    emptySet(&set);

    return set;
}