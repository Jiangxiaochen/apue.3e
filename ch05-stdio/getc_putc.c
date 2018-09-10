/*
 * =====================================================================================
 *    Description:  getc & putc
 *        Version:  1.0
 *        Created:  08/02/2018 01:48:26 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "apue.h"
int main(void)
{
	int c;

	while ((c = getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF)
			err_sys("output error");
	if (ferror(stdin))
		err_sys("input error");
	exit(0);
}
