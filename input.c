#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/signal.h>

int main(int argc, char const *argv[])
{
	char path[] = "2_max_subarray";
	int fd;
	int num;
	char buf[50];

	fd = open(path, O_WRONLY|O_NONBLOCK);
	
	while(gets(buf) != NULL){

		printf("buf: %s\n", buf);
		write(fd, buf, strlen(buf));

		sleep(1);
	}
	

	return 0;
}
