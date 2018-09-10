/*
 * =====================================================================================
 *    Description:  solution for pratice 3.2
 *        Version:  1.0
 *        Created:  07/30/2018 05:55:55 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int dup2_jxc(int oldfd, int newfd);

int main(int argc, const char *argv[])
{
    int tmp_fd = dup2_jxc(STDOUT_FILENO, 5);
    printf("%d\n", tmp_fd);
    write(STDOUT_FILENO, "abc\n", 4);
    write(5, "cde\n", 4);
    return 0;
}

#ifdef OPEN_MAX
	static long openmax = OPEN_MAX;
#else
	static long openmax = 0;
#endif

#define OPEN_MAX_GUESS 256                      /* inadequate */

long open_max(void)
{
	if (openmax == 0) {
		errno = 0;
		if((openmax = sysconf(_SC_OPEN_MAX)) < 0){
			if(errno == 0)
				openmax = OPEN_MAX_GUESS;
			else{
				fprintf(stderr, "sysconf error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	return openmax;
}

int dup2_jxc(int oldfd, int newfd)
{
    if (oldfd < 0 || newfd < 0 || newfd > open_max()) { /* arg error */
        errno = EBADF;
        return -1;
    }

    int tmp_fd;
    if((tmp_fd = dup(oldfd)) == -1) return -1;  /* fd not valid or error */
    close(tmp_fd);

    if (oldfd == newfd) return oldfd;                       /* fd is same */

    if ((tmp_fd = dup(newfd)) != -1) {                  /* newfd is open, need close */
        close(tmp_fd);
        close(newfd);
    }

    int *fds = malloc(sizeof(int) * newfd);  /* arr to store fd */
    if(fds == NULL){
        fprintf(stderr, "\ndynamic memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    while ((tmp_fd = dup(oldfd)) < newfd) {
        if (tmp_fd == -1 || tmp_fd == newfd) break; /* error or reach dest */
        fds[index++] = tmp_fd;
    }

    int i;
    for (i = 0; i < index; i++) {
        close(fds[i]);                          /* remember to close fd */
    }
    free(fds);                                  /* remember to free malloced mem */
    return tmp_fd;
}
