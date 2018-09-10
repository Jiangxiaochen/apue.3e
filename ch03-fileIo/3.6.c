/*
 * =====================================================================================
 *    Description:  test for p3.6
 *        Version:  1.0
 *        Created:  07/30/2018 09:54:26 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <bits/stat.h>

char buf[10];

int main(int argc, const char *argv[])
{
    int fd;
    fd = open("1.txt", O_RDWR | O_APPEND);
    if(fd == -1){
        fprintf(stderr, "open 1.txt error\n");
        exit(EXIT_FAILURE);
    }

    lseek(fd, 50, SEEK_SET);

    read(fd, buf, 10);
    write(STDOUT_FILENO, buf, 10);

    int ret = write(fd, "xiaochen.jiang", 14);

    read(fd, buf, 10);
    write(STDOUT_FILENO, buf, 10);

//    lseek(fd, 0, SEEK_SET);
//    write(fd, "haha", 4);


    read(fd, buf, 10);
    write(STDOUT_FILENO, buf, 10);
    read(fd, buf, 10);
    write(STDOUT_FILENO, buf, 10);
    return 0;
}
