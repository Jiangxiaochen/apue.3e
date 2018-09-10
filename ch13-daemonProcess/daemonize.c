#include <common.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <syslog.h>
#include <sys/stat.h>
#include <fcntl.h>

void daemonize(const char *cmd)
{
	int i, fd0, fd1, fd2;
	pid_t pid;
	struct rlimit rl;
	struct sigaction sa;
	umask(0);					/* clear file creation mask */
	chk_nega(getrlimit(RLIMIT_NOFILE, &rl));	/* get maximum number of fd */

	if ((pid = fork()) < 0) {
		err_quit("%s: can't fork", cmd);
	} else if (pid != 0) {
		exit(0);				/* parent exit */
	}
	setsid();					/* start new session without ctty */
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	chk_nega(sigaction(SIGHUP, &sa, NULL));     /* ignore sighup */
	chk_nega((pid = fork()));
	if (pid != 0)                               /* parent exit */
		exit(0);
	chk_nega(chdir("/"));                       /* change current working dir */
	if (rl.rlim_max == RLIM_INFINITY) {         /* get max fd */
		rl.rlim_max = 1024;
	}
	for (i = 0; i < rl.rlim_max; i++) {         /* close all fd */
		close(i);
	}

	fd0 = open("/dev/null", O_RDWR);            /* fd 0,1,2 attach to /dev/null */
	fd1 = dup(0);
	fd2 = dup(0);

	openlog(cmd, LOG_CONS, LOG_DAEMON);
	if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
		syslog(LOG_ERR, "unexpected file descriptors %d %d %d", fd0, fd1, fd2);
		exit(1);
	}
}
