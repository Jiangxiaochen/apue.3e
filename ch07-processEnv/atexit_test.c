/*
 * =====================================================================================
 *    Description:  test atexit
 *        Version:  1.0
 *        Created:  08/03/2018 03:54:53 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef void exit_handler(void);
exit_handler h1, h2, h3;
typedef void (*eh2) (void);
eh2 h3_ptr;

int main(int argc, const char *argv[])
{
	atexit(h1);
	atexit(h2);
	h3_ptr = h3;
	atexit(h3_ptr);
#ifdef ATEXIT_MAX
	printf("ATEXIT_MAX: %ld\n", ATEXIT_MAX);
#endif
	printf("_SC_ATEXIT_MAX: %ld\n", sysconf(_SC_ATEXIT_MAX));
	printf("LONG_MAX: %ld\n", LONG_MAX);

	return 0;
}

void h1(void)
{
	printf("%s\n", "h1 called");
}

void h2(void)
{
	printf("%s\n", "h2 called");
}

void h3(void)
{
	printf("%s\n", "h3 called");
}
