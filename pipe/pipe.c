#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#define STRLEN 1024

int main(void)
{
	int len;
	int fd[2];
	pid_t pid;	
	char str[] = "hello pipe\n";
	char str1[STRLEN];

	//创建管道
	if (pipe(fd) < 0) {
		perror("pipe");
		exit(1);
	}

	//创建子进程
	if ((pid = fork()) < 0) {
		perror("fork");
		exit(2);
	}

	if (pid > 0) {//父进程
		close(fd[0]);//关闭父读
		if (write(fd[1], str, sizeof(str)) < 0) {
			perror("write");
			exit(3);
		}
		wait(NULL);
	} else {
		close(fd[1]);//关闭子写
		len = read(fd[0], str1, STRLEN);
		if (len < 0) {
			perror("read");
			exit(4);
		}
		write(STDOUT_FILENO, str1, len);//输出到终端
	}

	return 0;
}
