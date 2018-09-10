/*
 * =====================================================================================
 *    Description:
 *        Version:  1.0
 *        Created:  08/07/2018 11:59:56 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	printf("%d\n", nice(1));
	printf("%d\n", nice(1));
	printf("%d\n", nice(1));
	printf("%d\n", nice(100));
	printf("%d\n", nice(-200));
	printf("%d\n", sysconf(_SC_NZERO));
	while (1) {

	}
	return 0;
}
