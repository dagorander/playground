#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;

	// First make a hardcoded array
	printf("Hardcoded array follows:\n");
	int hardcodedArray[] = {10, 11, 25, 26};

	// Access elements and print them out
	printf("0th element: %d\n", hardcodedArray[0]);
	printf("1st element: %d\n", hardcodedArray[1]);
	printf("2nd element: %d\n", hardcodedArray[2]);
	printf("3rd element: %d\n", hardcodedArray[3]);

	// Change the elements
	hardcodedArray[0] = 69;
	printf("Changed 0th to: %d\n", hardcodedArray[0]);

	// Loop our way through all this
	printf("Loopeloop: ");
	for (i = 0; i < 4; i++)
	{
		printf("%d, ", hardcodedArray[i]);
	}
	printf("\nNot perfect... let's do something dynamic.\n");

	// Let's purdy things up a bit
	printf("This should look better. Size of array is %lu\n",
			sizeof(hardcodedArray));
	printf("But that is in bytes, what is size of ints? 4. So:\n");
	printf("Sizeof divided by 4: %lu\n", sizeof(hardcodedArray)/4);
	printf("Definitely something that would want a function...\n\n");

	printf("And that's that for this one. :D\n\n");
	return 0;
}
