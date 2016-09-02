/*************************************************************************
  > File Name: fifo.c
  > Author: greezen
  > Mail: greezen@163.com 
  > Created Time: 2016年08月31日 星期三 16时51分48秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
	int fd, i=0;
	char pathname[] = "myfifo";//fifo名称
	char str[1024];

	//删除已存在的同名fifo文件
	unlink(pathname);

	//创建fifo文件
	if ((mkfifo(pathname, 0777) < 0) && (errno != EEXIST)) {
		perror("mkfifo");
		exit(1);
	}

	//以只写的方式打开fifio文件
	fd = open(pathname, O_WRONLY);
	if (fd == -1) {
		perror("open");
		exit(2);
	}

	//循环的往管道中写入数据
	while (1) {
		sprintf(str, "hello %d \n", i);
		if (write(fd, str, strlen(str)) < 0) {
			perror("write");
			exit(3);
		}
		i++;
		sleep(1);
	}

	close(fd);
	return 0;
}
