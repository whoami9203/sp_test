#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/signal.h>

#define MAX1 3
#define MAX2 4
#define count 5

int main(int argc, char const *argv[])
{
	char path1[] = "2_max_subarray";
	char path2[] = "3_max_subarray";
	char buf1[MAX][50] = {"   2\n   4\n  -3\n", "  -2\n", "  10\n"};
	char buf1[MAX][50] = {"   13\n  -5\n  -7\n", "   9\n", "   8\n", "  -1\n"};
	int fd1, fd2;
	pid_t pid1, pid2;	

	

	pid1 = fork();
	if(pid1 == 0){
		fd1 = open(path1, O_WRONLY|O_NONBLOCK);

		for(int i=0; i<MAX1; i++){

			printf("buf1: %s\n", buf1[i]);
			write(fd1, buf1[i], strlen(buf1[i]));

			sleep(4);
		}
	}
	else{
		pid2 = fork();
		if(pid2 == 0){
			fd2 = open(path2, O_WRONLY|O_NONBLOCK);

			for(int i=0; i<MAX2; i++){

				printf("buf2: %s\n", buf2[i]);
				write(fd2, buf2[i], strlen(buf2[i]));

				sleep(4);
			}
		}
		else{
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
	
	
	exit(0);
}
