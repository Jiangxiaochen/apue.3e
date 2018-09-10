/*
 * =====================================================================================
 *    Description:
 *        Version:  1.0
 *        Created:  08/06/2018 04:19:28 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <apue.h>

static void charatatime(char *str)
{
	char *ptr;
	int c;
	setbuf(stdout, NULL);
	for (ptr = str; (c = *ptr++) != 0;)
		putc(c, stdout);
}

int main(int argc, const char *argv[])
{
	pid_t pid;
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		charatatime("output from child\n");
	} else {
		charatatime("OUTPUT FROM PARENT\n");
	}
	return 0;
}
