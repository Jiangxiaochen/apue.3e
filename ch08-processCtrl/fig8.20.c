/*
 * =====================================================================================
 *    Description:
 *        Version:  1.0
 *        Created:  08/07/2018 09:54:24 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <apue.h>

int main(int argc, const char *argv[])
{
	pid_t pid;
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		if (execl
			("/root/apue.3e/ch08-processCtrl/echoarg", "jxctestinter",
			 "abc", "123", "jaksdkfj", (char *) 0) < 0) {
			err_sys("execl error");
		}
//		if (execl
//			("/root/apue.3e/ch08-processCtrl/interpreter_file", "jxctestinter",
//			 "abc", "123", "jaksdkfj", (char *) 0) < 0) {
//			err_sys("execl error");
//		}
	}

	if (waitpid(pid, NULL, 0) < 0) {
		err_sys("waitpid error");
	}
	return 0;
}
