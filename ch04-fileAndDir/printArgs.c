/*
 * =====================================================================================
 *    Description:  print arg's type
 *        Version:  1.0
 *        Created:  07/31/2018 09:23:05 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, const char *argv[])
{
    int i;
    struct stat buf;
    char *ptr;
    for (i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
        if (stat(argv[i], &buf) < 0) {
            fprintf(stderr, "lstat error\n");
            continue;
        }
        printf("%lu\n", buf.st_ino);
        if (S_ISREG(buf.st_mode)) {
            ptr = "regular";
        }else if (S_ISDIR(buf.st_mode)) {
            ptr = "directory";
        }else if (S_ISCHR(buf.st_mode)) {
            ptr = "character special";
        }else if (S_ISFIFO(buf.st_mode)) {
            ptr = "fifo";
        }else if (S_ISLNK(buf.st_mode)) {
            ptr = "symbolic link";
        }else if (S_ISSOCK(buf.st_mode)) {
            ptr = "socket";
        }else {
            ptr = "** unknown mode **";
        }
        printf("%s\n", ptr);
    }
    return 0;
}
