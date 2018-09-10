/*
 * =====================================================================================
 *
 *       Filename:  cp.c
 *
 *    Description:  cp stdin to stdout
 *
 *        Version:  1.0
 *        Created:  07/25/2018 01:06:58 PM
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
#include <string.h>


int main(int argc, const char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: ./a.out BUFFERSIZE\n");
		exit(EXIT_FAILURE);
	}
	int n;
	int BUFFERSIZE = atoi(argv[1]);

	char buf[BUFFERSIZE];
	while ((n = read(STDIN_FILENO, buf, BUFFERSIZE)) > 0) {
		if (write(STDOUT_FILENO, buf, n) != n) {
			fprintf(stderr, "write error\n");
			exit(EXIT_FAILURE);
		}
	}
	if (n < 0) {
		fprintf(stderr, "read error\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
