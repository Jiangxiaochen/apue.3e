/*
 * =====================================================================================
 *    Description:  solution for pratice 8.7
 *        Version:  1.0
 *        Created:  08/07/2018 09:30:56 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#define _GUN_SOURCE
#define _BSD_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <common.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, const char *argv[])
{
	DIR *dir_root;                              /* open dir */
	dir_root = opendir("/");
	chk_null(dir_root);

	int fd = dirfd(dir_root);                   /* get fd from DIR */
	chk_nega(fd);
	int ret = fcntl(fd, F_GETFD);

	printf("dir /: FD_CLOEXEC is %s\n", (ret & FD_CLOEXEC) ? "set": "unset");

	chk_nega(closedir(dir_root));
//	chk_nega(close(fd));

	fd = open("/", O_RDONLY);
	chk_nega(fd);
	printf("dir /: FD_CLOEXEC is %s\n", (ret & FD_CLOEXEC) ? "set": "unset");

	return 0;
}
