/*
 * =====================================================================================
 *    Description:  implement setbuf using setvbuf
 *        Version:  1.0
 *        Created:  08/02/2018 05:10:17 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void mysetbuf(FILE * stream, char *buf)
{
	if (buf == NULL) {
		setvbuf(stream, buf, _IONBF, 0);	/* no buf */
	} else {
		int mode = _IOFBF;		/* default full buf */
		if (isatty(fileno(stream)))
			mode = _IOLBF;		/* terminal device use line buf */
		setvbuf(stream, buf, mode, BUFSIZ);
	}
}

int main(int argc, const char *argv[])
{
	return 0;
}
