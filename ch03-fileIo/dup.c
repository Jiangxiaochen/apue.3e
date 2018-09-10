/*
 * =====================================================================================
 *    Description:  dup & dup2
 *        Version:  1.0
 *        Created:  07/30/2018 03:24:09 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd1 = dup(1);
	printf("%d\n", fd1);
	return 0;
}
