/*
 * =====================================================================================
 *    Description:  buffsize affect the effeciency of io
 *        Version:  1.0
 *        Created:  07/30/2018 01:29:54 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BUFFSIZE
	#define BUFFSIZE 32
#endif

int main(int argc, const char *argv[])
{
	int n;
	char buf[BUFFSIZE];
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
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


