#include <stdio.h>

int globalvar = 100;

void pass_by_value (int value) {
	
	value += 10;
	printf("\nPass by Value: %d", value);

}

void pass_by_pointer (int *value) {

	int tempval = * value;

	printf("\n");
	printf("\nExpect weird results:");
	printf("\nPass by Pointer: %d", * value);
	value += 10;
	printf("\nPass by Pointer: %d", * value);
	/* This gives random output! "Dangling pointer"? */

	printf("\n");
	printf("\nNow for a \"dereferenced\" pointer?");
	printf("\nDereferenced value: %d", tempval);
	tempval += 10;
	printf("\nDereferenced and added: %d", tempval);

}

void make_permanent (int *value) {

	int tempval = * value;
	tempval += 10;
	* value = tempval;

}

void modify_global_var () {

	globalvar += 10;

}


int main () {
	
	int x = 100;
	int y = 100;
	int z = 100;

	printf("\nInitial value of x: %d", x);
	pass_by_value(x);
	printf("\nFinal value of x: %d", x);
	printf("\nNote effect of scope!");

	printf("\n");
	printf("\nInitial value of y: %d", y);
	pass_by_pointer(& y);
	printf("\nFinal value of y: %d", y);

	printf("\n");
	printf("\nNow to make the value change permanent!");
	printf("\nInitial value of z: %d", z);
	make_permanent(& z);
	printf("\nFinal value of z: %d", z);

	printf("\n");
	printf("\nInitial value of globalvar: %d", globalvar);
	modify_global_var();
	printf("\nFinal value of globalvar: %d", globalvar);

	printf("\n");
	return 0;

}
