/*
 * =====================================================================================
 *    Description:  tmp name and file
 *        Version:  1.0
 *        Created:  08/02/2018 04:36:05 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "apue.h"
int main(void)
{
	char name[L_tmpnam], line[MAXLINE];
	FILE *fp;
	printf("%s\n", tmpnam(NULL));	/* first temp name */
	tmpnam(name);				/* second temp name */
	printf("%s\n", name);
	if ((fp = tmpfile()) == NULL)	/* create temp file */
		err_sys("tmpfile error");
	fputs("one line of output\n", fp);	/* write to temp file */
	rewind(fp);					/* then read it back */
	if (fgets(line, sizeof(line), fp) == NULL)
		err_sys("fgets error");
	fputs(line, stdout);		/* print the line we wrote */
	exit(0);
}
