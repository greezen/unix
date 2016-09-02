/*************************************************************************
	> File Name: mmap_w.c
	> Author: greezen
	> Mail: greezen@163.com 
	> Created Time: 2016年09月01日 星期四 16时14分23秒
 ************************************************************************/

#include<stdio.h>
#include<errno.h>

/**
 * 错误处理函数
 */
void show_err(char *str, int errno)
{
	perror(str);
	exit(errno);
}

int main(argc, char *argv[])
{
	int fd,i=0;

	if (argc < 2) {
		printf
	}

	fd = open()
}
