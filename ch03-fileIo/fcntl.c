/*
 * =====================================================================================
 *    Description:  fcntl
 *        Version:  1.0
 *        Created:  07/30/2018 04:06:50 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void set_fl(int fd, int flags)
{
    int val;
    if((val = fcntl(fd, F_GETFL, 0)) < 0){
        fprintf(stderr, "fcntl F_GETFL error\n");
        exit(EXIT_FAILURE);
    }
    val |= flags;
    if (fcntl(fd, F_SETFL, val) < 0) {
        fprintf(stderr, "fcntl F_SETFL error\n");
        exit(EXIT_FAILURE);
    }
}

void clr_fl(int fd, int flags)
{
    int val;
    if((val = fcntl(fd, F_GETFL, 0)) < 0){
        fprintf(stderr, "fcntl F_GETFL error\n");
        exit(EXIT_FAILURE);
    }
    val &= ~flags;
    if (fcntl(fd, F_SETFL, val) < 0) {
        fprintf(stderr, "fcntl F_SETFL error\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, const char *argv[])
{
	int val;
	if (argc != 2) {
		fprintf(stderr, "usage: a.out fd\n");
		exit(EXIT_FAILURE);
	}
	if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
		fprintf(stderr, "fcntl error for fd %d\n", atoi(argv[1]));
		exit(EXIT_FAILURE);
	}
	switch(val & O_ACCMODE)
	{
		case O_RDONLY:
			printf("read only\n");
			break;
		case O_WRONLY:
			printf("write only\n");
			break;
		case O_RDWR:
			printf("read write\n");
			break;
		default:
			fprintf(stderr, "unknown access mode\n");
			exit(EXIT_FAILURE);
			break;
	}
	if (val & O_APPEND) {
		printf(", append");
	}
    if (val & O_NONBLOCK) {
        printf(", nonblocking");
    }
    if (val & O_SYNC) {
        printf(", synchronous writes");
    }
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC) {
        printf(", synchronous writes");
    }
#endif
    putchar('\n');
    return 0;
}
