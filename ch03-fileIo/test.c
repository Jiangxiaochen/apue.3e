/*
 * =====================================================================================
 *    Description:
 *        Version:  1.0
 *        Created:  07/30/2018 09:40:39 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    int fd;
    fd = open("1.txt", O_RDWR | O_APPEND);
    if(fd == -1){
        fprintf(stderr, "open 1.txt error\n");
        exit(EXIT_FAILURE);
    }

    char buf[10];
    read(fd, buf, 10);
    write(STDOUT_FILENO, buf, 10);
    read(fd, buf, 10);
    write(STDOUT_FILENO, buf, 10);
    read(fd, buf, 10);
    write(STDOUT_FILENO, buf, 10);
}
