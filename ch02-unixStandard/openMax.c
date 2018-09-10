/*
 * =====================================================================================
 *    Description:  最大打开文件数目兼容
 *        Version:  1.0
 *        Created:  07/27/2018 04:30:10 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>

#ifdef OPEN_MAX
	static long openmax = OPEN_MAX;
#else
	static long openmax = 0;
#endif

#define OPEN_MAX_GUESS 256                      /* inadequate */

long open_max(void)
{
	if (openmax == 0) {
		errno = 0;
		if((openmax = sysconf(_SC_OPEN_MAX)) < 0){
			if(errno == 0)
				openmax = OPEN_MAX_GUESS;
			else{
				fprintf(stderr, "sysconf error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	return openmax;
}

int main(int argc, const char *argv[])
{
	printf("%ld\n", open_max());
	return 0;
}
