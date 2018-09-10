/*
 * =====================================================================================
 *    Description:  test for p4.16
 *        Version:  1.0
 *        Created:  07/31/2018 01:53:06 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>
#include <apue.h>
#include <ftw.h>

#define PATH_MAX 100000
static int handler(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{

    printf("%s start remove\n",fpath+ftwbuf->base);
    open
    if (S_ISDIR(sb->st_mode)) {
        if (rmdir(fpath) == -1) {
            perror("rmdir");
            exit(-1);
        }
    }
    if (typeflag == FTW_F) {
        if (unlink(fpath) == -1)
        {
            perror("unlink");
            exit(-1);
        }
    }
    printf("%s remove success\n",fpath+ftwbuf->base);
    return 0;
}

char path[PATH_MAX+20000];
int main(int argc, const char *argv[])
{
    if (strcmp(argv[1], "clear") == 0) {
        nftw("jxc_dir_loop1000", handler, 100, FTW_DEPTH);
    }
    if (strcmp(argv[1],"c") == 0) {
        int num = 1000;
        char name[100];
        while (num) {
            sprintf(name, "%s%d","jxc_dir_loop",num);
            mkdir(name, DIR_MODE);
            chdir(name);
            num--;
        }
    }
    if (strcmp(argv[1], "v") == 0) {
        int num = 1000;
        char name[100];
        while( num) {
            sprintf(name, "%s%d", "jxc_dir_loop", num);
            num--;
            chdir(name);
        }
        char * ptr = getcwd(path, PATH_MAX+20000);
        if (ptr == NULL) err_sys("getcwd error");
        printf("%s\n", path);
    }


    return 0;
}
