#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int
main(void)
{
	if (open("temp_dir", O_RDWR) < 0){
		printf("failed");
		exit(0);
	}

	printf("file opened\n");
	sleep(15);
	printf("done\n");
	exit(0);
	}
