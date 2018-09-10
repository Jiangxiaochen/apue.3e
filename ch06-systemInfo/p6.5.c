/*
 * =====================================================================================
 *    Description:  solution for 6.5
 *        Version:  1.0
 *        Created:  08/03/2018 03:19:09 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <apue.h>
#include <common.h>

int main(int argc, const char *argv[])
{
    //Fri Aug  3 15:18:58 CST 2018
    time_t now;
    struct tm *tm;
    char line[MAXLINE];

    chk_nega(now = time(NULL));
    chk_null(tm = localtime(&now));
    chk_zero(strftime(line, MAXLINE, "%a %b %d %X %Z %Y\n", tm));
    fputs(line, stdout);
    return 0;
}
