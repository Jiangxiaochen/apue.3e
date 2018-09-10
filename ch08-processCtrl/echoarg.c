/*
 * =====================================================================================
 *    Description:
 *        Version:  1.0
 *        Created:  08/07/2018 09:48:35 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	while (*argv)
		printf("%s\n", *argv++);
	return 0;
}
