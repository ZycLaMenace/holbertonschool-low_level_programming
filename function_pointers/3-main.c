#include "3-calc.h"

/**
 * main - do simple operations
 * 
*/

int main (int argc, char *argv[])
{
	int num1, num2, result;
	int (*operation)(int, int);

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);


if (argc != 4)
{
	printf("Error\n");
	exit (98);
}
	operation = get_op_func(argv[2]);

if (operation == NULL)
{
	printf("Error\n");
	exit (99);
}

 if ((argv[2][0] == '/' || argv[2][0] == '%') && num2 == 0)
{
	printf("Error\n");
	exit (100);
}
    result = operation(num1, num2);
    printf("%d\n", result);

    return (0);

}
