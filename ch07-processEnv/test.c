/*
 * =====================================================================================
 *    Description:
 *        Version:  1.0
 *        Created:  08/05/2018 06:25:55 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <common.h>

int init_data = 100;
int bss_udata;

int main(int argc, const char *argv[])
{
//    while (*environ) {
//        printf("%s\n", *environ);
//        environ++;
//    }
	printf("%p\n", environ[1]);
	char *v = getenv("PATH");
	chk_null(v);
	printf("env['PATH']: %p\n", v);             /* environ */
    printf("stack[v]: %p\n", &v);               /* stack */
	printf("%s\n", v);
	int a = putenv("jxc123=jxc456");
    if (a != 0) {
        fprintf(stderr, "putenv error\n");
        exit(EXIT_FAILURE);
    }
    char *v1 = getenv("jxc123");
    chk_null(v1);
    printf("%p\n", v1);
    char *h = malloc(1);
    char *h2 = malloc(1);
    printf("heap: %p %p\n", h, h2);             /* heap */
    printf("v1 maybe heap?: %p\n", v1);         /* put env */
    printf("bss: %p\n", &bss_udata);
    printf("data: %p\n", &init_data);
    return 0;
}
