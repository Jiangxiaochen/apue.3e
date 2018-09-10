#include <common.h>
#include <pthread.h>

pthread_mutex_t putenv_mutex;

int putenv_r(char *str)
{
	sigset_t new_sigset, old_sigset;
	chk_nega(sigfillset(&new_sigset));
	chk_nega(sigprocmask(SIG_BLOCK, &new_sigset, &old_sigset));	/* block all signal */

	int err = pthread_mutex_lock(&putenv_mutex);	/* lock the mutex */
	if (err != 0) {
		err_exit(err, "lock putenv_mutex failed");
	}

	int ret = putenv(str);		/* call putenv */
	err = pthread_mutex_unlock(&putenv_mutex);	/* unlock the mutex */
	if (err != 0) {
		err_exit(err, "unlock putenv_mutex failed");
	}

	chk_nega(sigprocmask(SIG_BLOCK, &old_sigset, NULL));	/* unblock all signal */

	return ret;
}

int main(int argc, const char *argv[])
{
	putenv_r("JXC=XXT");
	printf("%s\n", getenv("JXC"));
	return 0;
}
