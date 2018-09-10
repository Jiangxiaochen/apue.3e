/*
 * =====================================================================================
 *
 *       Filename:  time.c
 *
 *    Description:  time
 *
 *        Version:  1.0
 *        Created:  07/25/2018 05:53:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 *   Organization:  LINUX.COMMUNITY
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, const char *argv[])
{

struct timezone
  {
    int tz_minuteswest;		/* Minutes west of GMT.  */
    int tz_dsttime;		/* Nonzero if DST is ever in effect.  */
  };
	time_t a;
	time_t b = time(&a);                        /* seconds since epoch */
//date(1), gettimeofday(2), ctime(3), ftime(3), time(7)
	struct timeval tv;
	struct timezone tz;
	int res;
	res = gettimeofday(&tv, &tz);
	if (res == -1) {
		fprintf(stderr, "gettimeofday error\n");
		exit(EXIT_FAILURE);
	}
	printf("%lu %lu\n",tv.tv_sec, tv.tv_usec);
	printf("%d %d\n", tz.tz_dsttime, tz.tz_minuteswest);
	printf("%lu %lu\n", a, b);
	struct tm *utc_tm, *cst_tm;
	utc_tm = gmtime(&a);
	cst_tm = localtime(&a);
	char *utc_char, *cst_char;
	utc_char = asctime(utc_tm);
	printf("%s\n",utc_char);
	cst_char = asctime(cst_tm);
	printf("%s\n",cst_char);
//	char *ctime(const time_t *timep);
//	time_t mktime(struct tm *tm);
	return 0;
}
