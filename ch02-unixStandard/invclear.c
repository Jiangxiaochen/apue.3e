/*
 * =====================================================================================
 *    Description:  data structure in out
 *        Version:  1.0
 *        Created:  07/27/2018 03:31:04 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts;

int main(int argc, const char *argv[])
{
	FILE *fp;
	fp = fopen("invent.dat", "rb+");
	if(fp == NULL){
		fprintf(stderr, "\nCan't open %s\n", "invent.dat");
		exit(EXIT_FAILURE);
	}

	/*-----------------------------------------------------------------------------
	 *  写出流程
	 *-----------------------------------------------------------------------------*/
	if (argv[1] == "out") {
	}
	/*-----------------------------------------------------------------------------
	 *  读入并修改流程
	 *-----------------------------------------------------------------------------*/
	int i = 0;
	num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, fp);
	for (i = 0; i < num_parts; i++) {
		inventory[i].on_hand = 0;
	}
	rewind(fp);                                 /* 缺少这一步会在文件末尾添加数据,而不是覆盖旧数据 */
	fwrite(inventory, sizeof(struct part), num_parts, fp);
	fclose(fp);
	fp = NULL;
	return 0;
}
