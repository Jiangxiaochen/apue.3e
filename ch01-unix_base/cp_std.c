/*
 * =====================================================================================
 *
 *       Filename:  cp_std.c
 *
 *    Description:  cp stdin to stdout using stdlib
 *
 *        Version:  1.0
 *        Created:  07/25/2018 02:07:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 *   Organization:  LINUX.COMMUNITY
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
	int c;
	while ((c = getc(stdin)) != EOF) {
		if (putc(c, stdout) == EOF) {
			fprintf(stderr, "output error\n");
			exit(EXIT_FAILURE);
		}
	}
	if (ferror(stdin)) {
		fprintf(stderr, "input error\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
