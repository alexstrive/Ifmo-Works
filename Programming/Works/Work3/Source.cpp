#include <stdio.h>

void show_number_representation(const int number, int base)
{
	switch (base)
	{
	case 8:
		printf("Octal number: %o\n", number);
		break;
	case 16:
		printf("Hexadecimal number: %x\n", number);
		break;
	default:
		printf("Decimal number: %d\n", number);
		break;
	}
}

void print_title(const int taskNumber)
{
	printf("\n--- Task %d ---\n", taskNumber);
}

void pause()
{
	printf("\nPlease enter any key to exit...");
	getchar();
	getchar();
}

// Variant - 9
int main()
{
	int numberFirst;
	int numberSecond;

	// task 1
	print_title(1);
	printf("Enter first number (hexadecimal): ");
	scanf_s("%x", &numberFirst);

	// task 2
	print_title(2);
	show_number_representation(numberFirst, 8);

	// task 3
	print_title(3);
	show_number_representation(numberFirst, 8);
	show_number_representation(numberFirst << 1, 8);

	// task 4
	print_title(4);
	show_number_representation(numberFirst, 8);
	show_number_representation(~numberFirst, 8);

	// task 5
	print_title(5);
	printf("Enter second number (octal): ");
	scanf_s("%o", &numberSecond);
	show_number_representation(numberFirst & numberSecond, 8);

	pause();
	return 0;
}
