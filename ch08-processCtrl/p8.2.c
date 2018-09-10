/*
 * =====================================================================================
 *    Description:  verify practice 8.2
 *        Version:  1.0
 *        Created:  08/07/2018 03:01:31 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void call_vfork()
{
	if (vfork() == 0) {
		_exit(0);
	}else{
		printf("%s\n", "ha");
	}
}

int main(int argc, const char *argv[])
{
	call_vfork();
	return 0;
}
