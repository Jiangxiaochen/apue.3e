/*
 * =====================================================================================
 *    Description:  difference between iso c and posix.1
 *        Version:  1.0
 *        Created:  07/27/2018 05:31:38 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>

int main(int argc, const char *argv[])
{
	printf("%lu\n", CLOCKS_PER_SEC);
	printf("%lu\n", sysconf(_SC_CLK_TCK));
	printf("iso cpu time:%lus\n", clock() / CLOCKS_PER_SEC);
	struct tms tms1;

	while (1) {
		int i;
		for (i = 0; i < 100000000; i++) {
			/* code */
		}
		printf("iso cpu time:%lus\n", clock() / CLOCKS_PER_SEC); /* 注意clock返回clock_t类型的值,但是除以100000 */
		times(&tms1);
		clock_t total = tms1.tms_cstime + tms1.tms_cutime + tms1.tms_stime + tms1.tms_utime;
		printf("pos cpu time:%lus\n", total / sysconf(_SC_CLK_TCK)); /* times也返回clock_t类型的值,但是除以100，这就是标准之间的冲突 */
	}
	return 0;
}
