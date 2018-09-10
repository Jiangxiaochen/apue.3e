/*
 * =====================================================================================
 *    Description:  solution for ex15.12
 *        Version:  1.0
 *        Created:  08/29/2018 05:06:24 PM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <common.h>
#include <sys/msg.h>
#include <sys/ipc.h>

int main(int argc, const char *argv[])
{
	int i, queue_id;
	key_t key;
	for (i = 0; i < 5; i++) {
		chk_nega((key = ftok("/dev/null", i)));
		chk_nega((queue_id =
				  msgget(key, IPC_CREAT | IPC_EXCL | S_IWUSR | S_IRUSR)));
		printf("queue_id: %d\n", queue_id);
		chk_nega(msgctl(queue_id, IPC_RMID, NULL));
	}

	char msg[] = "hello";
	for (i = 0; i < 5; i++) {
		chk_nega((queue_id =
				  msgget(IPC_PRIVATE,
						 IPC_CREAT | IPC_EXCL | S_IWUSR | S_IRUSR)));
		printf("queue_id: %d\n", queue_id);
		chk_nega(msgsnd(queue_id, msg, sizeof(msg), 0));
	}
	return 0;
}
