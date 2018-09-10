/*
 * =====================================================================================
 *
 *       Filename:  shellLike.c
 *
 *    Description:  a program like shell
 *
 *        Version:  1.0
 *        Created:  07/25/2018 02:44:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 *   Organization:  LINUX.COMMUNITY
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <apue.h>
#define MAXLINE 10

static void sigint(int);

int main(int argc, const char *argv[])
{
	if (signal(SIGINT, sigint) == SIG_ERR) {    /* register signal handler */
		fprintf(stderr, "signal error\n");
		exit(EXIT_FAILURE);
	}
	char buf[MAXLINE];
	pid_t pid;
	int status;
	printf("%% ");                             /* print prompt */
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf) - 1] == '\n') {
			buf[strlen(buf) - 1] = 0;           /* replace n */
		}
		if ((pid = fork()) < 0) {
			fprintf(stderr, "fork error\n");
			exit(EXIT_FAILURE);
		}else if (pid == 0) {
			execlp(buf, buf,(char *)0);
			fprintf(stderr, "couldn't execut'\n", buf);
			exit(127);
		}
		//paren
		if ((pid = waitpid(pid, &status, 0)) < 0) {
			fprintf(stderr, "waitpid error\n");
			exit(EXIT_FAILURE);
		}
		printf("%% ");
	}
	return 0;
}
void sigint(int a)
{
	if (a == SIGINT) {
		printf("a == SIGINT\n");
	}
	printf("interrupt\n%%");
}
