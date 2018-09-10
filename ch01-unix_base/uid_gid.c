/*
 * =====================================================================================
 *
 *       Filename:  uid_gid.c
 *
 *    Description:  print uid & gid
 *
 *        Version:  1.0
 *        Created:  07/25/2018 05:06:28 PM
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
#include <grp.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	printf("uid = %d, gid = %d\n", getuid(), getgid());
	return 0;
}
