#include <stdio.h>
#include <math.h>

double degreeToRadian(double degree) {
    return degree * M_PI / 180;
}

double functionFirst(double radian) {
    return 2 * pow(sin(3 * M_PI - 2 * radian), 2) * pow(cos(5 * M_PI + 2 * radian), 2);
}

double functionSecond(double radian) {
    return 0.25 - 0.25 * sin(2.5 * M_PI - 8 * radian);
}

// Variant 1
int main() {
    double degree, radian;

    printf("Enter degree: ");
    scanf("%lf", &degree);

    radian = degreeToRadian(degree);
    printf("Z1: %f\n", functionFirst(radian));
    printf("Z2: %f\n", functionSecond(radian));

    return 0;
}