#include <common.h>
#include <sys/shm.h>

#define ARRAY_SIZE	40000
#define MALLOC_SIZE	100000
#define SHM_SIZE	100000
#define SHM_MODE	0600

static char array[ARRAY_SIZE];

int main(int argc, const char *argv[])
{
	int shmid;
	char *ptr, *shmptr;

	printf("array[] from %p to %p\n", array, &array[ARRAY_SIZE - 1]);
	printf("stack around %p\n", &shmid);

	chk_null((ptr = malloc(MALLOC_SIZE)));
	printf("malloced from %p to %p\n", ptr, ptr + MALLOC_SIZE - 1);

	chk_nega((shmid = shmget(IPC_PRIVATE, SHM_SIZE, SHM_MODE)));
	if ((shmptr = shmat(shmid, 0, 0)) == (void *) -1) {
		err_sys("shmat error");
	}
	printf("shared memory attached from %p to %p\n", shmptr,
		   shmptr + SHM_SIZE - 1);
	chk_nega(shmctl(shmid, IPC_RMID, 0));
	return 0;
}
