/*
 * =====================================================================================
 *    Description:  test
 *        Version:  1.0
 *        Created:  08/08/2018 01:43:17 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	printf("%d\n", getpgrp());
	printf("%d\n", getpid());
	return 0;
}
