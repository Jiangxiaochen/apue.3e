/*
 * =====================================================================================
 *
 *       Filename:  printSelfPid.c
 *
 *    Description:  print self pid
 *
 *        Version:  1.0
 *        Created:  07/25/2018 02:29:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 *   Organization:  LINUX.COMMUNITY
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	printf("hello world from process ID %ld\n", (long)getpid());
	return 0;
}
