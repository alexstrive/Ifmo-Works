#include <stdio.h>
#include <math.h>

void showTitle(const int task_number) {
    printf("--- Task %d ---\n", task_number);
}

float calculateCircuit(float radius) {
    return M_PI * 2 * radius;
}

float calculateArea(float radius) {
    return M_PI * pow(radius, 2);
}

char *format_state(int state) {
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
    showTitle(1);
    printf("Symbian is %d\n", OS_SYMBIAN);

    // Task 2
    showTitle(2);

    const struct Circle circle = {50, 10, 5.0f, 1.5f};

    printf("Caclulated curcuit: %f \n", calculateCircuit(circle.radius));
    printf("Calculated area: %f \n", calculateArea(circle.radius));

    // Task 3
    showTitle(3);
    printf("Enter keyboard state: ");
    scanf("%x", &keyboard.state);

    printf("Num Lock is %s\n", format_state(keyboard.bitState.numLock));
    printf("Caps Lock is %s\n", format_state(keyboard.bitState.capsLock));
    printf("Scroll Lock is %s\n", format_state(keyboard.bitState.scrollLock));

    return 0;
}