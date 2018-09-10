/*
 * =====================================================================================
 *    Description:  solution for practice 10.6
 *        Version:  1.0
 *        Created:  08/10/2018 06:03:34 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <common.h>

int main(int argc, const char *argv[])
{
	FILE *fp;
	fp = fopen("1.txt", "r+");
	chk_null(fp);
	fputs("0", fp);
	fclose(fp);

	pid_t pid;
	chk_nega((pid=fork()));
	if (pid >0) {
		while (1) {
			fp = fopen("1.txt", "r+");
		}
	}
	return 0;
}
