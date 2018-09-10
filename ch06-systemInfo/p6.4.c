/*
 * =====================================================================================
 *    Description:  max time_t
 *        Version:  1.0
 *        Created:  08/03/2018 02:28:19 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>
#include <common.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
    time_t JXC = 1;
    printf("%lu \n", sizeof(time_t));
    int bits_lshift = sizeof(time_t) * 8 -1;
    JXC <<= bits_lshift;
    time_t JXC2 = 1;
    if (JXC < JXC2) {
        printf("%s\n", "time_t is signed");
    }else {
        printf("%s\n", "time_t is unsigned");
    }

    time_t max = ~0;
    max <<= bits_lshift;
    max -= 2;
    printf("%ld\n", max);
    printf("%ld\n", LONG_MAX);
    time_t haha = LONG_MAX;

    struct tm *ptr = gmtime(&haha);
    chk_null(ptr);
    char time_str[100];
    strftime(time_str, 100, "%Y-%m-%d %H-%M-%S", ptr);
    printf("%s\n", time_str);
    return 0;
}
