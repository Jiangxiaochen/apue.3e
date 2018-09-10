/*
 * =====================================================================================
 *    Description:  test mem stream
 *        Version:  1.0
 *        Created:  08/03/2018 09:10:07 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <common.h>

static char buf[BUFSIZ];
#define mode "wb+"

int main(int argc, const char *argv[])
{
    FILE *fp_mem = fmemopen(buf, BUFSIZ, mode);
    chk_null(fp_mem);

	return 0;
}
