/*
 * =====================================================================================
 *    Description:  futimes
 *        Version:  1.0
 *        Created:  08/01/2018 12:15:21 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    int i,fd;
    struct stat statbuf;
    struct timespec times[2];

    for (i = 0; i < argc; i++) {
        /* code */
    }
    return 0;
}
