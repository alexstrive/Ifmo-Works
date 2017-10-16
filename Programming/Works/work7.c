#include <stdio.h>
#include <math.h>
#include "utils.h"

float calculateCircuit(float radius) {
    return (float) (M_PI * 2 * radius);
}

float calculateArea(float radius) {
    return (float) (M_PI * pow(radius, 2));
}

char *formatState(int state) {
    return state == 1 ? "On" : "Off";
}

enum OS {
    OS_SYMBIAN,
    OS_EMBEDDED_LINUX,
    OS_WINDOWS_CE,
    OS_VXWORKS,
    OS_QNX
};

struct Circle {
    int x;
    int y;
    float radius;
    float borderWidth;
    int color;
    int borderColor;
};

union Keyboard {
    unsigned short state;
    struct {
        unsigned short numLock : 1;
        unsigned short capsLock : 1;
        unsigned short scrollLock : 1;
    } bitState;
} keyboard;

// Variant 9
int main() {
    // Task 1
    showTaskTitle();

    printf("Symbian is %d\n", OS_SYMBIAN);

    // Task 2
    showTaskTitle();

    const struct Circle circle = {50, 10, 5.0f, 1.5f};

    printf("Caclulated curcuit: %f \n", calculateCircuit(circle.radius));
    printf("Calculated area: %f \n", calculateArea(circle.radius));

    // Task 3
    showTaskTitle();

    printf("Enter keyboard state (hexadecimal): ");
    scanf("%x", &keyboard.state);

    printf("Num Lock is %s\n", formatState(keyboard.bitState.numLock));
    printf("Caps Lock is %s\n", formatState(keyboard.bitState.capsLock));
    printf("Scroll Lock is %s\n", formatState(keyboard.bitState.scrollLock));

    return 0;
}