#include <stdio.h>
#include <stdlib.h>


int
main ()
{

	int x, y, z, result, max;

	printf("\nTHIS IS A USEFUL PROGRAM! HONEST!");
	printf("\nInput an integer: ");
	scanf("%d", &x);
	printf("\nInput another integer: ");
	scanf("%d", &y);
	printf("\nInput a third integer: ");
	scanf("%d", &z);
	result=(x+y+abs(x-y))/2;
	max=(result+z+abs(result-z))/2;
	printf("\nThe highest value was: %d\n", max);
	return 0;
}
