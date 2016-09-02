#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	if(argc < 2){
		printf("file name must \n");
		exit(1);
	}
	umask(0);
	fd = open(argv[1], O_CREAT, 0644);
	printf("fd = %d\n", fd);
	return 0;
}
