/*
 * =====================================================================================
 *    Description:  test unlink
 *        Version:  1.0
 *        Created:  07/31/2018 09:31:57 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <apue.h>

int main(int argc, const char *argv[])
{
    if (open("tmpfile", O_RDWR) < 0) {
        err_sys("open error");
    }
    if (unlink("tmpfile") < 0) {
        err_sys("unlink error");
    }
    printf("file unlinked\n");
    sleep(15);
    printf("done\n");
    return 0;
}
