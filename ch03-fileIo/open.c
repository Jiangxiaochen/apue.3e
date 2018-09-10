/*
 * =====================================================================================
 *    Description:  open & openat
 *        Version:  1.0
 *        Created:  07/30/2018 09:58:47 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
	int fd = open("dir1/1.txt", O_RDONLY);
	printf("%d\n", fd);
	int fd2 = openat(1314, "/root/apue.3e/ch03-fileIo/dir1/1.txt", O_RDONLY);
	printf("%d\n", fd2);
	return 0;
}
