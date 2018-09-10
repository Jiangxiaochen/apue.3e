/*
 * =====================================================================================
 *    Description:  solution for practice 9.2
 *        Version:  1.0
 *        Created:  08/08/2018 03:58:47 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <common.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
	pid_t pid;
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {		/* child */
		chk_nega(setsid());
		//check is group leader
		printf("child %s process group leader\n",
			   getpid() == getpgid(0) ? "is" : "isn't");
		//check has controlling terminal
		printf("child %s controlling terminal\n",
			   tcgetpgrp(STDOUT_FILENO) == -1 ? "hasn't" : "has");
	} else {					/* parent */
		waitpid(pid, NULL, 0);
	}
	return 0;
}
