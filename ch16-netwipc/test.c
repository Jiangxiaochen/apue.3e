/*
 * =====================================================================================
 *    Description:  test for endian
 *        Version:  1.0
 *        Created:  08/30/2018 09:06:58 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <common.h>

int main(int argc, const char *argv[])
{
	if(jxc_getEndian() == JXC_ENDIAN_BIG) printf("JXC_ENDIAN_BIG\n");
	if(jxc_getEndian() == JXC_ENDIAN_LIT) printf("JXC_ENDIAN_LIT\n");
	return 0;
}
