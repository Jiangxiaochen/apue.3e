/*
 * =====================================================================================
 *    Description:  imp of nftw
 *        Version:  1.0
 *        Created:  08/01/2018 09:24:19 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <apue.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>

#define und_t 0
#define reg_t 1
#define dir_t 2
#define blk_t 3
#define chr_t 4
#define fif_t 5
#define slk_t 6
#define soc_t 7

typedef int Myfunc(const char * pathName, const struct stat * stat_buf, int type); /* called for every entry */
static Myfunc myfunc;                           /* this func is to record file type num */
static int myftw(const char *, Myfunc *);             /* my impletation of nftw */
static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot; /* record the num of different type of file */
char name[1000];                                /* save the pathname */
struct stat stat_buf;                           /* stat */
int type;                                       /* file type */

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage a.out pathname\n");
        exit(EXIT_FAILURE);
    }
    strcpy(name, argv[1]);
    myftw(name, myfunc);
    ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock;
    if (ntot == 0) {
        ntot = 1;
    }
    printf("regular files       = %7ld, %5.2f %%\n", nreg, nreg*100.0/ntot);
    printf("directories         = %7ld, %5.2f %%\n", ndir, ndir*100.0/ntot);
    printf("block special       = %7ld, %5.2f %%\n", nblk, nblk*100.0/ntot);
    printf("char special        = %7ld, %5.2f %%\n", nchr, nchr*100.0/ntot);
    printf("fifos               = %7ld, %5.2f %%\n", nfifo, nfifo*100.0/ntot);
    printf("symbolic links      = %7ld, %5.2f %%\n", nslink, nslink*100.0/ntot);
    printf("sockets             = %7ld, %5.2f %%\n", nsock, nsock*100.0/ntot);
    return 0;
}

static int myftw(const char * pathName, Myfunc *func)
{
    struct dirent *dirp;
    DIR *dp;
    size_t pathlen;
    if (lstat(pathName, &stat_buf) == -1)	type = und_t;
    if (S_ISREG(stat_buf.st_mode))	type = reg_t;
    if (S_ISDIR(stat_buf.st_mode))	type = dir_t;
    if (S_ISBLK(stat_buf.st_mode))	type = blk_t;
    if (S_ISCHR(stat_buf.st_mode))	type = chr_t;
    if (S_ISFIFO(stat_buf.st_mode))	type = fif_t;
    if (S_ISLNK(stat_buf.st_mode))	type = slk_t;
    if (S_ISSOCK(stat_buf.st_mode))	type = soc_t;

    func(pathName, &stat_buf, type);
    if (type == dir_t) {
        dp = opendir(pathName);
        if (dp == NULL) return 0;
        while ((dirp = readdir(dp)) != NULL) {
            if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) {
                continue;
            }
            pathlen = strlen(pathName);
            name[pathlen++] = '/';
            name[pathlen] = 0;
            strcat(name, dirp->d_name);
            myftw(name, func);
            name[pathlen-1] = 0;
        }
    }

    return 0;
}

int myfunc(const char * pathName, const struct stat * stat_buf, int type)
{
    switch(type)
    {
        case blk_t: nblk++; break;
        case chr_t: nchr++; break;
        case dir_t: ndir++; break;
        case fif_t: nfifo++; break;
        case reg_t: nreg++; break;
        case slk_t: nslink++; break;
        case soc_t: nsock++; break;
        case und_t: break;
    }
    return 0;
}

