#define _BSD_SOURCE				/* feature test macros */
#include "apue.h"
#include <unistd.h>
#include <sys/types.h>
#include <common.h>
int globvar = 6;				/* external variable in initialized data */
int main(void)
{
	int var;					/* automatic variable on the stack */
	pid_t pid;
	var = 88;
	int fd = dup(STDOUT_FILENO);	/* copy std fd */
	chk_nega(fd);
	printf("before vfork\n");	/* we don’t flush stdio */
	if ((pid = vfork()) < 0) {
		err_sys("vfork error");
	} else if (pid == 0) {		/* child */
		globvar++;				/* modify parent’s variables */
		var++;
//      _exit(0);               /* child terminates */
		fclose(stdout);			/* close stdout */
		_exit(0);
	}
/* parent continues here */
	int ret =
		printf("pid = %ld, glob = %d, var = %d\n", (long) getpid(), globvar,
			   var);
	char buf[100] = { 0 };
	sprintf(buf, "%d\n", ret);
	write(fd, buf, sizeof(buf));
	exit(0);
}
