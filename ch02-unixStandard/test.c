/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  07/27/2018 10:15:23 AM
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

int main(int argc, const char *argv[])
{
	FILE *fp1;
	fp1 = fopen(".vimrc", "rw");
	if(fp1 == NULL){
		fprintf(stderr, "\nCan't open %s\n", ".vimrc");
		exit(EXIT_FAILURE);
	}


	fclose(fp1);
	fp1 = NULL;
	return 0;
}
