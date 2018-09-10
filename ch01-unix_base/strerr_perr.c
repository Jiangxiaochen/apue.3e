/*
 * =====================================================================================
 *
 *       Filename:  strerr_perr.c
 *
 *    Description:  strerr vs perr
 *
 *        Version:  1.0
 *        Created:  07/25/2018 03:36:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 *   Organization:  LINUX.COMMUNITY
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	int arr[] = {EAGAIN,ENFILE,ENOBUFS,ENOLCK,ENOSPC,EWOULDBLOCK,ENOMEM,EBUSY,EINTR};
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
		fprintf(stderr, "%d:%s\n", i, strerror(arr[i]));
	}
	errno = ENOENT;
	perror(argv[0]);
	return 0;
}
