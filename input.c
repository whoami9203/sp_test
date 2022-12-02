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

#define MAX 3

int main(int argc, char const *argv[])
{
	char path[] = "2_max_subarray";
	int fd;
	int num;
	char buf[MAX][50] = {"1111\n", "   1\n", " 123\n"};

	//fd = open(path, O_WRONLY|O_NONBLOCK);
	
	for(int i=0; i<MAX; i++){

		printf("buf: %s, lenth: %d\n", buf[i], strlen(buf[i]));
		//write(fd, buf, strlen(buf[i]));

		sleep(2);
	}
	

	return 0;
}
