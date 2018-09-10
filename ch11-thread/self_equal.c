/*
 * =====================================================================================
 *    Description:  test pthread
 *        Version:  1.0
 *        Created:  08/13/2018 03:26:57 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, const char *argv[])
{
	pthread_t tid;
	tid = pthread_self();
	pthread_t tid2 = pthread_self();

	int ret = pthread_equal(tid, tid2);
	printf("%d\n", ret);
	return 0;
}
