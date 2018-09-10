/*
 * =====================================================================================
 *    Description:  test umask's function
 *        Version:  1.0
 *        Created:  07/31/2018 02:18:25 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <apue.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(int argc, const char *argv[])
{
    mode_t old_mask = umask(0);
    printf("%o\n", old_mask);
    if (creat("foo", RWRWRW) < 0) {
        err_sys("creat error for foo");
    }
    mode_t tmp = umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    printf("%o\n", tmp);
    if (creat("bar", RWRWRW) < 0) {
        err_sys("creat error for bar");
    }
//    tmp = umask(old_mask);
//    printf("%o\n", tmp);
    return 0;
}

