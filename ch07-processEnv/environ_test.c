/*
 * =====================================================================================
 *    Description:
 *        Version:  1.0
 *        Created:  08/03/2018 04:47:01 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int a[100];
double d = 10;

int main(int argc, const char *argv[])
{
    int index = 0;
    while (environ[index] != NULL) {
        printf("%s\n", environ[index]);
        index++;
    }
    return 0;
}
