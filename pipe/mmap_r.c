/*************************************************************************
	> File Name: mmap_w.c
	> Author: greezen
	> Mail: greezen@163.com 
	> Created Time: 2016年09月01日 星期四 16时14分23秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<fcntl.h>
#define MAPLEN 0x1000

/**
 * 错误处理函数
 */
void handle_err(char *str, int err_no)
{
	perror(str);
	exit(err_no);
}

struct PHONE {
	char type[16];
	char version[16];
	char color[16];
};

int main(int argc, char *argv[])
{
	int fd,i=0;
	struct PHONE *mm;

	if (argc < 2) {
		printf("please input a pathname\n");
		exit(1);
	}

	fd = open(argv[1], O_RDWR);
	if	(fd < 0) {
		handle_err("open", 2);	
	}

	mm = mmap(NULL, MAPLEN, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (mm == MAP_FAILED) {
		handle_err("mmap", 5);
	}

	close(fd);
	
	while (1) {
		printf("%s %s %s\n", mm->type, mm->version, mm->color);
		i++;
	}

	munmap(mm, MAPLEN);

	return 0;
}
