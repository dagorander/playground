#include <stdio.h>
#include <stdlib.h>


// Examples taken from: https://www.tutorialspoint.com/cprogramming/c_file_io.htm


int main ()
{
	FILE *fp;
	
	FILE *fr;
	char buff[255];

	// Write a file
	fp = fopen("./test.txt", "w+");
	fprintf(fp, "This is testing fprintf...\n");
	fputs("This is testing fputs\n", fp);
	fclose(fp);

	printf("In theory, file is written, time to read.\n");

	// Read the file
	fr = fopen("./test.txt", "r");
	fscanf(fr, "%s", buff); // read until space?
	printf("1: %s\n", buff);
	fgets(buff, 255, (FILE*)fr); // fgets reads until end of line?
   	printf("2: %s\n", buff );
   
   	fgets(buff, 255, (FILE*)fr);
   	printf("3: %s\n", buff );
   	fclose(fr);

	// TODO: Figure out how to append to a file
	// TODO: Create a function to write arbitrary stuff to a file
	// TODO: Make it be as many lines as user happens to want
	// TODO: Then read the file and print out all of them

	return 0;
}
