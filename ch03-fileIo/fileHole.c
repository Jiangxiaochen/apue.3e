/*
 * =====================================================================================
 *    Description:  creat a file which contains hole
 *        Version:  1.0
 *        Created:  07/30/2018 11:15:08 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <apue.h>

const char *buf1 = "abcdefghij";
const char *buf2 = "ABCDEFGHIJ";
int main(int argc, const char *argv[])
{
	int fd;
	if((fd = creat("file.hole", FILE_MODE)) < 0) err_sys("creat error");
	if (write(fd, buf1, 10) != 10) {
		err_sys("buf1 write error");            /* offset now = 10 */
	}
	if (lseek(fd, 16384, SEEK_SET) == -1) {
		err_sys("lseek error");
	}
	if (write(fd, buf2, 10) != 10) {
		err_sys("buf2 write error");
	}

	long int r1 = sysconf(_SC_V7_ILP32_OFF32);
	long int r2 = sysconf(_SC_V7_ILP32_OFFBIG);
	long int r3 = sysconf(_SC_V7_LP64_OFF64);
	long int r4 = sysconf(_SC_V7_LPBIG_OFFBIG);

	printf("%ld %ld %ld %ld\n", r1, r2, r3, r4);

	return 0;
}
