/*
 * =====================================================================================
 *    Description:
 *        Version:  1.0
 *        Created:  07/31/2018 04:06:26 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, const char *argv[])
{
    struct stat buf;
    stat(argv[1], &buf);
    printf("%ld\n", buf.st_size);
    printf("%ld\n", buf.st_blksize);
    printf("%ld\n", buf.st_blocks);
    return 0;
}
