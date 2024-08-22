#include "main.h"

/**
 * _strlen - calculate the length of a string
 *@s: string to be tested
 * Return: length of string
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
	}
	return (i);
}


/**
 * infinite_add - additionne deux nombres
 * @n1: premier nombre
 * @n2: deuxième nombre
 * @r: buffer pour stocker le résultat
 * @size_r: taille du buffer
 * Return: pointeur vers le résultat, ou 0 si impossible
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int l1 = _strlen(n1) - 1, l2 = _strlen(n2) - 1, carry = 0;
	int sum, i = size_r - 2;

	r[size_r - 1] = '\0';

	while (l1 >= 0 || l2 >= 0 || carry)
	{
		if (i < 0)
			return (0);

		sum = carry;
		if (l1 >= 0)
			sum += n1[l1--] - '0';
		if (l2 >= 0)
			sum += n2[l2--] - '0';

		carry = sum / 10;
		r[i--] = (sum % 10) + '0';
	}

	return (&r[i + 1]);
}
