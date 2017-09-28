#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

void pause()
{
	printf("\nPlease enter any key to exit...\n");
	getchar();
	getchar();
}

void print_title(const int task_number)
{
	printf("--- Task %d ---\n", task_number);
}

float calculate_circuit(float radius)
{
	return M_PI * 2 * radius;
}

float calculate_area(float radius)
{
	return M_PI * pow(radius, 2);
}

enum OS
{
	OS_SYMBIAN,
	OS_EMBEDDED_LINUX,
	OS_WINDOWS_CE,
	OS_VXWORKS,
	OS_QNX
};

struct Circle
{
	int x;
	int y;
	float radius;
} circle;

struct Keyboard
{
	unsigned num_lock: 1;
	unsigned caps_lock: 1;
	unsigned scroll_lock: 1;
} keyboard;

// Variant 9
int main()
{
	// Task 1
	print_title(1);
	printf("%d \n", OS_SYMBIAN);
	
	// Task 2
	print_title(2);

	circle.x = 50;
	circle.y = 10;
	circle.radius = 5.0;

	printf("Caclulated curcuit: %f \n", calculate_circuit(circle.radius));
	printf("Calculated area: %f \n", calculate_area(circle.radius));

	// Task 3
	int device_state;
	print_title(3);
	printf("Enter device state: ");
	scanf("%x", &device_state);
	printf("%d", keyboard.caps_lock | device_state);

	pause();

	return 0;
}