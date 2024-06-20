#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/* betty style doc for function main goes there */
int main(void)
{
int n;
int last_digit;
last_digit = n % 10;
srand(time(0));
n = rand() - RAND_MAX / 2;
if(last_digit >= 5)
printf("Last digit of %d is %d and is greater than 5 \n",n,last_digit);
}
