#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	const char *p1 = "/root/apue.3e/ch02-unixStandard/r";
	const char *p = "r";
	FILE *fp;
	fp = fopen(p1, p);
	if(fp == NULL){
		fprintf(stderr, "\nCan't open %s\n", p);
		exit(EXIT_FAILURE);
	}
	char ptr[100];
	memset(ptr, 0, sizeof(ptr));
	int n = fread(ptr,sizeof(char), 100, fp);
	if (n < 10000) {
		if (feof(fp) != 0) {
			fprintf(stderr, "read to eof\n");
		}
		if (ferror(fp) != 0) {
			fprintf(stderr, "read error\n");
		}
	}
	printf("%d\n", n);
	printf("%s", ptr);
	printf("%lu\n", strlen(ptr));
	fclose(fp);
	fp = NULL;
	return 0;
}
