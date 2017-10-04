#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

void pause()
{
	printf("\nPlease enter any key to exit...\n");
	getchar();
	getchar();
}

void show_title(const int task_number)
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

char* format_state(int state)
{
	return state == 1 ? "On" : "Off";
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
	float border_width;
};

union Keyboard
{
	unsigned short state;
	struct
	{
		unsigned short num_lock : 1;
		unsigned short caps_lock : 1;
		unsigned short scroll_lock : 1;
	} bit_state;
} keyboard;

// Variant 9
int main()
{
	// Task 1
	show_title(1);
	printf("Symbian is %d OS\n", OS_SYMBIAN);

	// Task 2
	show_title(2);

	const struct Circle circle = {50, 10, 5.0f, 1.5f};

	printf("Caclulated curcuit: %f \n", calculate_circuit(circle.radius));
	printf("Calculated area: %f \n", calculate_area(circle.radius));

	// Task 3
	show_title(3);
	printf("Enter keyboard state: ");
	scanf("%x", &keyboard.state);

	printf("Num Lock is %s\n", format_state(keyboard.bit_state.num_lock));
	printf("Caps Lock is %s\n", format_state(keyboard.bit_state.caps_lock));
	printf("Scroll Lock is %s\n", format_state(keyboard.bit_state.scroll_lock));
	
	pause();
	return 0;
}
