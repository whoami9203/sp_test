#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int
main(void)
{
	if (open("tempfile", O_RDWR) < 0)
		err_sys("open error");

	printf("file opened\n");
	sleep(15);
	printf("done\n");
	exit(0);
	}
