#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

double degree_to_radian(float degree)
{
	return degree * M_PI / 180;
}

double function_first(double radian)
{
	return 2 * pow(sin(3 * M_PI - 2 * radian), 2) * pow(cos(5 * M_PI + 2 * radian), 2);
}

double function_second(double radian)
{
	return 0.25 - 0.25 * sin(2.5 * M_PI - 8 * radian);
}

void pause()
{
	printf("\nPlease enter any key to exit... \n");
	getchar();
	getchar();
}

// Variant 1
int main()
{
	// Radians or Degrees?
	float degree;
	float radian;
	printf("Enter degree: ");
	scanf_s("%f", &degree);

	radian = degree_to_radian(degree);
	printf("Z1: %f\n", function_first(radian));
	printf("Z2: %f\n", function_second(radian));

	pause();
	return 0;
}
