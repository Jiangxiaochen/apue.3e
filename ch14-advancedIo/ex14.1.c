/*
 * =====================================================================================
 *    Description:  solution for ex14.1
 *        Version:  1.0
 *        Created:  08/22/2018 04:44:50 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <common.h>
static int flag_other_is_done = 0;
void chld_handler(int data)
{
	flag_other_is_done = 1;
}

int main(int argc, const char *argv[])
{
	int fd;
	fd = open("1.txt", O_CREAT | O_RDWR | O_TRUNC, FILE_MODE);
	if (fd == -1) {
		fprintf(stderr, "open 1.txt error\n");
		exit(EXIT_FAILURE);
	}
	write(fd, "123", 3);
	chk_nega(read_lock(fd, 0, SEEK_SET, 0));	/* parent read lock */
	printf("parent get read_lock\n");
	int pid;
	chk_sig(mysignal(SIGCHLD, chld_handler));
	chk_nega((pid = fork()));
	if (pid == 0) {
		while (flag_other_is_done == 0)
			pause();
		flag_other_is_done = 0;
		chk_nega(read_lock(fd, 0, SEEK_SET, 0));
		printf("child get read_lock\n");
		kill(getppid(), SIGCHLD);
		while (1) {
			chk_nega(un_lock(fd, 0, SEEK_SET, 0));
			printf("child un_lock\n");
			sleep(2);
			chk_nega(read_lock(fd, 0, SEEK_SET, 0));
			printf("child read_lock\n");
		}
	}
	if (pid != 0) {
		chk_nega(un_lock(fd, 0, SEEK_SET, 0));
		printf("parent un_lock\n");
		kill(pid, SIGCHLD);
		while (flag_other_is_done == 0)
			pause();
		flag_other_is_done = 0;
		while (write_lock(fd, 0, SEEK_SET, 0) == -1) {
			printf("parent get write_lock failed, sleep 5s...\n");
			sleep(5);
		}
		printf("parent get write lock\n");
	}
	return 0;
}
