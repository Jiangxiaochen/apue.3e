/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  for some test
 *
 *        Version:  1.0
 *        Created:  07/26/2018 10:04:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 *   Organization:  LINUX.COMMUNITY
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	printf("%ld\n", sysconf(_SC_ARG_MAX));
	printf("%ld\n", sysconf(_SC_ATEXIT_MAX));
	printf("%ld\n", sysconf(_SC_CHILD_MAX));
	printf("%ld\n", sysconf(_SC_COLL_WEIGHTS_MAX));
	printf("%ld\n", sysconf(_SC_CLK_TCK));
	return 0;
}
