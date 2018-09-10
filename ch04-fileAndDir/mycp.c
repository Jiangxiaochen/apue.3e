/*
 * =====================================================================================
 *    Description:  like cp
 *        Version:  1.0
 *        Created:  08/01/2018 04:07:52 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <apue.h>

#define buf_size 4096
char buf[buf_size];

int main(int argc, const char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s srcFile dstFile\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int fd;
    fd = open(argv[1], O_RDONLY);
    if(fd == -1){
        fprintf(stderr, "open %s error\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int fd_out;
    fd_out = open(argv[2], O_CREAT|O_TRUNC|O_WRONLY);
    if(fd_out == -1){
        fprintf(stderr, "open %s error\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    off_t off_start, off_end, off_cur;
    off_start = lseek(fd, 0, SEEK_SET);
    off_end = lseek(fd, 0, SEEK_END);
    off_cur = off_start;

    while (1) {
       off_t hole_start = lseek(fd, off_cur, SEEK_HOLE) ;
       off_t hole_end = lseek(fd, hole_start, SEEK_DATA);
       off_t num_to_read = hole_start - off_cur;
       while (num_to_read > 0) {
           int n;
           if (num_to_read >= buf_size) n = buf_size;
           else n = num_to_read;
           if (read(fd, buf, n) < 0) {
               err_sys("read error");
           }
           if (write(fd_out, buf, n) != n) {
               err_sys("write error");
           }
           num_to_read -= n;
       }
       lseek(fd_out, hole_end, SEEK_SET);
       off_cur = hole_end;
       if (hole_start == off_end) {
           break;
       }
    }
    return 0;
}
