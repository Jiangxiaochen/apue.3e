/*
 * =====================================================================================
 *    Description:  solution for 6.3
 *        Version:  1.0
 *        Created:  08/03/2018 02:13:08 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <common.h>

int main(int argc, const char *argv[])
{
	struct utsname buf;
	chk_nega(uname(&buf));
	printf("%s/%s/%s/%s/%s/%s\n", buf.sysname, buf.nodename, buf.release,
		   buf.version, buf.machine, buf.domainname);
	return 0;
}
