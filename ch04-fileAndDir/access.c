/*
 * =====================================================================================
 *    Description:  test access function
 *        Version:  1.0
 *        Created:  07/31/2018 11:22:56 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: a.out <pathname>\n");
        exit(EXIT_FAILURE);
    }

    if (access(argv[1], R_OK) < 0) {
        fprintf(stderr, "access error for %s\n", argv[1]);
    }else {
        printf("read access ok\n");
    }

    if (open(argv[1], O_RDONLY) < 0) {
        fprintf(stderr, "open error for %s\n", argv[1]);
    }else {
        printf("open for reading OK\n");
    }
    return 0;
}
