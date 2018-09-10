/*
 * =====================================================================================
 *    Description:  study for file pos
 *        Version:  1.0
 *        Created:  07/27/2018 02:47:17 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char buf[100];

int main(int argc, const char *argv[])
{
	FILE *fp;
	fp = fopen("1.c", "rb");
	if(fp == NULL){
		fprintf(stderr, "\nCan't open %s\n", "1.c");
		exit(EXIT_FAILURE);
	}
	setvbuf(fp, buf, _IOFBF, sizeof(buf));
	printf("%s\n", buf);
	long pos = ftell(fp);                       /* 获取当前位置 */
	printf("%ld\n", pos);
	printf("%c\n", fgetc(fp));
	printf("%s\n",buf);
	printf("%ld\n", ftell(fp));
	fseek(fp, -7L, SEEK_END);
	fpos_t a;
	a.__anon283::__pos
		k
	printf("%s\n",buf);
	printf("%ld\n", ftell(fp));
	fclose(fp);
	fp = NULL;
//	int a = fseek(FILE *stream, long offset, int whence);
//	long ftell(FILE *stream);
//	void rewind(FILE *stream);
//	int fgetpos(FILE *stream, fpos_t *pos);
//	int fsetpos(FILE *stream, fpos_t *pos);os
	return 0;
}
