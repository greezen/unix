#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int src dest;
	if(argc < 3){
		printf("file name must \n");
		exit(1);
	}
	umask(0);
	src = open(argv[1], O_CREAT | O_RDONLY, 0644);
	dest = open(argv[2], O_CREAT | O_WRONLY, 0644);
	printf("fd = %d\n", fd);
	return 0;
}
