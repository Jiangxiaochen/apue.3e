/*
 * =====================================================================================
 *    Description:
 *        Version:  1.0
 *        Created:  07/27/2018 03:50:49 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <apue.h>
#include <errno.h>
//
#ifdef PATH_MAX
static long pathmax = PATH_MAX;
#else
static long pathmax = 0;
#endif

static long posix_version = 0;
static long xsi_version = 0;

// 如果 PATH_MAX 未定义, 不保证这是准确的
#define PATH_MAX_GUESS 1024

char * path_alloc(size_t *sizep)                /* 如果非空, 也返回分配的大小 */
{
	if (posix_version == 0) {
		posix_version = sysconf(_SC_VERSION);
	}
	if (xsi_version == 0) {
		xsi_version = sysconf(_SC_XOPEN_VERSION);
	}
	if (pathmax == 0) {                         /* 第一次经过 */
		errno = 0;
		if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0) {
			if(errno == 0)
				pathmax = PATH_MAX_GUESS;
			else
				err_sys("pathconf error fo _PC_PATH_MAX");
		}else{
			pathmax++;
		}
	}
	/*-----------------------------------------------------------------------------
	 *  POSIX.1-2001之前特殊处理
	 *-----------------------------------------------------------------------------*/
	char *ptr;
	size_t size;
	if ((posix_version < 200112L) && (xsi_version < 4)) {
		size = pathmax + 1;
	}else{
		size = pathmax;
	}

	ptr = malloc(size);
	if(ptr == NULL){
		fprintf(stderr, "\ndynamic memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	if (sizep != NULL) {
		*sizep = size;
	}
	return ptr;
}

int main(int argc, const char *argv[])
{
	getcwd(
	return 0;
}
