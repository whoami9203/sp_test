#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int
main(void)
{
	if (open("tempfile", O_RDWR) < 0)
		exit(0);

	printf("file opened\n");
	sleep(15);
	printf("done\n");
	exit(0);
	}
