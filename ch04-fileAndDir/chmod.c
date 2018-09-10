/*
 * =====================================================================================
 *    Description:  chmod
 *        Version:  1.0
 *        Created:  07/31/2018 03:08:36 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <apue.h>

int main(int argc, const char *argv[])
{
    struct stat stat_buf;
    if (stat("foo", &stat_buf) < 0) {
        err_sys("stat error for foo");
    }
    if (chmod("foo", (stat_buf.st_mode & ~S_IXGRP) | S_ISGID) < 0) {
        err_sys("chmod error for foo");
    }

    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) {
        err_sys("chmod error for bar");
    }
    return 0;
}
