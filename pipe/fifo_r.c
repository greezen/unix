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

int main(void)
{
	int fd, len;
	char pathname[] = "myfifo";
	char str[1024];

	//以只读的方式打开fifo文件
	fd = open(pathname, O_RDONLY);
	if (fd == -1) {
		perror("open");
		exit(2);
	}

	//循环的从fifo文件中读取数据
	while (1) {
		if ((len = read(fd, str, sizeof(str))) < 0) {
			perror("read");
			exit(3);
		} else {
			write(STDOUT_FILENO, str, len);
		//	printf("%s", str);
		}
	}

	close(fd);
	return 0;
}
