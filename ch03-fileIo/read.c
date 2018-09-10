/*
 * =====================================================================================
 *    Description:  read
 *        Version:  1.0
 *        Created:  07/30/2018 11:56:49 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BUF_SIZE
#define BUF_SIZE 5
#endif

int main(int argc, const char *argv[])
{
	char buf[BUF_SIZE];
	long int read_num;
	while ((read_num = read(STDIN_FILENO, buf, BUF_SIZE)) == BUF_SIZE) {
		long int wr_num = write(STDOUT_FILENO, buf, BUF_SIZE);
		if (wr_num != BUF_SIZE) {
			fprintf(stderr, "error occured\n");
			exit(EXIT_FAILURE);
		}
	}

	printf("%ld\n", read_num);
	return 0;
}
