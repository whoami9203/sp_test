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

#define MAX 2
#define count 5

int main(int argc, char const *argv[])
{
	char path[] = "2_max_subarray";
	int fd;
	int num;
	char buf[MAX][50] = {"   2\n   4\n  -3\n", " 197\n"};

	fd = open(path, O_WRONLY|O_NONBLOCK);
	
	for(int i=0; i<MAX; i++){

		printf("buf: %s\n", buf[i]);
		write(fd, buf[i], strlen(buf[i]));

		sleep(11);
	}
	

	return 0;
}
