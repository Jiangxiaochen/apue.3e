/*
 * =====================================================================================
 *    Description:  test for p3.3
 *        Version:  1.0
 *        Created:  07/30/2018 09:15:17 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    int fd1, fd2, fd3;
    fd1 = open("1.txt", O_RDONLY);
    fd2 = dup(fd1);
    fd3 = open("1.txt", O_RDONLY);

    /*-----------------------------------------------------------------------------
     *  test F_SETFD's effect
     *-----------------------------------------------------------------------------*/
    printf("%d\n", fcntl(fd1, F_GETFD));
    printf("%d\n", fcntl(fd2, F_GETFD));
    printf("%d\n", fcntl(fd3, F_GETFD));
    int ret;
    if ((ret = fcntl(fd1, F_SETFD, 1)) == -1) {
        fprintf(stderr, "F_SETFD erro\n");
        exit(EXIT_FAILURE);
    }
    printf("%d\n", fcntl(fd1, F_GETFD));
    printf("%d\n", fcntl(fd2, F_GETFD));
    printf("%d\n", fcntl(fd3, F_GETFD));

    /*-----------------------------------------------------------------------------
     *  test F_SETFL's effect
     *-----------------------------------------------------------------------------*/
    printf("%d\n", fcntl(fd1, F_GETFL));
    printf("%d\n", fcntl(fd2, F_GETFL));
    printf("%d\n", fcntl(fd3, F_GETFL));
    if ((ret = fcntl(fd1, F_SETFL, O_APPEND)) == -1) {
        fprintf(stderr, "F_SETFL error\n");
        exit(EXIT_FAILURE);
    }
    printf("%d\n", fcntl(fd1, F_GETFL));
    printf("%d\n", fcntl(fd2, F_GETFL));
    printf("%d\n", fcntl(fd3, F_GETFL));
    return 0;
}
