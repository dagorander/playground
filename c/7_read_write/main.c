#include <stdio.h>
#include <stdlib.h>

// Examples taken from: 
// https://www.tutorialspoint.com/cprogramming/c_file_io.htm
// and other random googles

// Testing file listing
#include <dirent.h>


void list_dir ()
{
	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}

	// TODO: Make it list file types (at least ident folders)
}

int main ()
{
	FILE *fp;
	
	FILE *fr;
	char buff[255];

	printf("List files before\n");
	list_dir();

	// Write a file
	fp = fopen("./test.txt", "w+");
	fprintf(fp, "This is testing fprintf...\n");
	fputs("This is testing fputs\n", fp);
	fclose(fp);

	printf("In theory, file is written, time to read.\n");

	printf("Directory contents:\n");
	list_dir();

	// Read the file
	fr = fopen("./test.txt", "r");
	fscanf(fr, "%s", buff); // read until space?
	printf("1: %s\n", buff);
	fgets(buff, 255, (FILE*)fr); // fgets reads until end of line?
   	printf("2: %s\n", buff );
   
   	fgets(buff, 255, (FILE*)fr);
   	printf("3: %s\n", buff );
   	fclose(fr);

	// List files in directory
	

	// Delete the file
	if (remove("./test.txt") == 0) 
	{
		printf("File removed successfully\n");
	} 
	else 
	{
		printf("File deletion failed\n");
	}
	
	printf("Final contents:\n");
	list_dir();

	// TODO: Figure out how to append to a file
	// TODO: Create a function to write arbitrary stuff to a file
	// TODO: Make it be as many lines as user happens to want
	// TODO: Then read the file and print out all of them

	return 0;
}
