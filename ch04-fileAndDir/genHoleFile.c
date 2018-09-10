/*
 * =====================================================================================
 *    Description:  generate a file with hole
 *        Version:  1.0
 *        Created:  07/31/2018 04:21:44 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, const char *argv[])
{
    umask(0777);
    int fd;
    fd = open("fileWithHole", O_WRONLY|O_CREAT|O_TRUNC, 0);
    if(fd == -1){
        fprintf(stderr, "open fileWithHole error\n");
        exit(EXIT_FAILURE);
    }
    const char *str = "jxc is creating a file with hole:";
    write(fd, str, strlen(str));

    lseek(fd, 12345, SEEK_SET);

    const char *str2 = ": hole end. Success!";
    write(fd, str2, strlen(str2));
    return 0;
}
