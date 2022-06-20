#include <sys/types.h>
#include <sys/sysctl.h>
// Those above are for system information
// Not sure if they are what I want, see man -s 2 sysctl

#include <stdio.h>



int main () {
	printf("Testing\n");

	/*
	 * From that sysctl thing
	
	int mib[2], maxproc;
	size_t len;

	mib[0] = CTL_KERN;
	mib[1] = KERN_MAXPROC;
	len = sizeof(maxproc);
	if (sysctl(mib, 2, &maxproc, &len, NULL, 0) == -1)
		err(1, "sysctl");

	 *
	 */

	return 0;
}
