/*
 * =====================================================================================
 *    Description:  link
 *        Version:  1.0
 *        Created:  08/01/2018 03:45:22 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    if (symlink(NULL, "jxclnk") == -1) {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("link success\n");
    return 0;
}
