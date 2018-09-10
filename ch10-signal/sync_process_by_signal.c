#include <common.h>

static volatile sig_atomic_t sigflag;
static sigset_t newmask, oldmask, zeromask;
static struct sigaction act;

static void sig_usr(int signo)
{
	sigflag = 1;
}

void tell_wait(void)
{
	chk_nega(sigaction(SIGUSR2, &act, NULL));	/* register sighandler */
	chk_nega(sigaction(SIGUSR1, &act, NULL));

	sigemptyset(&zeromask);		/* block usr1 & usr2 */
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGUSR1);
	sigaddset(&newmask, SIGUSR2);

	chk_nega(sigprocmask(SIG_BLOCK, &newmask, &oldmask));
}

void tell_parent(pid_t pid)
{
	kill(pid, SIGUSR2);
}

void wait_parent(void)
{
	while (sigflag == 0)
		sigsuspend(&zeromask);
	sigflag = 0;
	chk_nega(sigprocmask(SIG_SETMASK, &oldmask, NULL));
}

void tell_child(pid_t pid)
{
	kill(pid, SIGUSR1);
}

void wait_child(void)
{
	while (sigflag == 0)
		sigsuspend(&zeromask);
	sigflag = 0;
	chk_nega(sigprocmask(SIG_SETMASK, &oldmask, NULL));
}

int main(int argc, const char *argv[])
{
	act.sa_handler = sig_usr;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	pid_t pid;
	int i;
	chk_nega((pid = fork()));
	if (pid == 0) {
		for (i = 0; i < 100000; i++) {
			printf("%s", "a");
		}
	} else {
		for (i = 0; i < 100000; i++) {
			printf("%s", "A");
		}
	}
	return 0;
}
