#include <stdio.h>
#include <stdlib.h>

int main () {

	// This pointer will hold the base adress
	// of the block created.
	int* ptr;
	int n, i;

	printf("\nJust playing around with memory allocation and arrays.\n");

	// Get the number of elements for the array
	printf("Enter the number of elements: ");
	scanf("%d",&n); // Take input, pass it into the adress held by n
			// Why is that an adress and not just the var?
	printf("\nNumber of elements entered: %d\n", n);

	// Dynamically allocate memory using malloc
	ptr = (int*)malloc(n * sizeof(int));

	// Check if allocation was successful
	if (ptr == NULL) {
		printf("Memory not allocated! PANIC!\n");
		exit(0);
	}
	else {
		
		printf("Memory successfully allocated!\n");

		// Get the elements of the array.
		for (i = 0; i < n; ++i) {
			ptr[i] =  i + i;
		}

		// Print the elements of the array.
		printf("The elements of the array are: ");
		for (i = 0; i < n; ++i) {
			printf("%d, ", ptr[i]);
		}
	}
	
	printf("\nFor shizzles, adress of array thingie: %pc", ptr);

	printf("\n");
	return 0;
}
