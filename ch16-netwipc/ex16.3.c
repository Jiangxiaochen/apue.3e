#include "apue.h"
#include <netdb.h>
#include <errno.h>
#include <syslog.h>
#include <sys/socket.h>
#include <common.h>
#define BUFLEN 128
#define QLEN 10
#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 256
#endif
#define MAX_SOCKFD 256
extern int initserver(int, const struct sockaddr *, socklen_t, int);
void serve(int *sockfds, int fd_num)
{
	int clfd;
	FILE *fp;
	char buf[BUFLEN];
	fd_set read0, read1;
	FD_ZERO(&read0);			/* 修改前 */
	FD_ZERO(&read1);			/* 修改后 */
	int max_sock_fd = -1;		/* 最大fd */
	int i;
	for (i = 0; i < fd_num; i++) {
		FD_SET(sockfds[i], &read0);
		set_cloexec(sockfds[i]);
		if (sockfds[i] > max_sock_fd) {
			max_sock_fd = sockfds[i];
		}
	}
	read1 = read0;
	for (;;) {
		read0 = read1;			/* 恢复 */
		chk_nega(select(max_sock_fd + 1, &read0, NULL, NULL, NULL));
		for (i = 0; i < fd_num; i++) {
			if (FD_ISSET(sockfds[i], &read0)) {

				if ((clfd = accept(sockfds[i], NULL, NULL)) < 0) {
					syslog(LOG_ERR, "ruptimed: accept error: %s",
						   strerror(errno));
					exit(1);
				}
				set_cloexec(clfd);
				if ((fp = popen("ps aux | wc -l", "r")) == NULL) {
					sprintf(buf, "error: %s\n", strerror(errno));
					send(clfd, buf, strlen(buf), 0);
				} else {
					while (fgets(buf, BUFLEN, fp) != NULL)
						send(clfd, buf, strlen(buf), 0);
					pclose(fp);
				}
				close(clfd);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	struct addrinfo *ailist, *aip;
	struct addrinfo hint;
	int sockfd, err, n;
	char *host;
	if (argc != 1)
		err_quit("usage: ruptimed");
	if ((n = sysconf(_SC_HOST_NAME_MAX)) < 0)
		n = HOST_NAME_MAX;		/* best guess */
	if ((host = malloc(n)) == NULL)
		err_sys("malloc error");
	if (gethostname(host, n) < 0)
		err_sys("gethostname error");
	daemonize("ruptimed");
	memset(&hint, 0, sizeof(hint));
	hint.ai_flags = AI_CANONNAME;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;
	if ((err = getaddrinfo(host, "ruptime", &hint, &ailist)) != 0) {
		syslog(LOG_ERR, "ruptimed: getaddrinfo error: %s", gai_strerror(err));
		exit(1);
	}
	int sockfds[MAX_SOCKFD];	/* store sockfd */
	int i = 0;
	for (aip = ailist; aip != NULL; aip = aip->ai_next) {
		if ((sockfd = initserver(SOCK_STREAM, aip->ai_addr,
								 aip->ai_addrlen, QLEN)) >= 0) {
//          serve(sockfd);
			sockfds[i++] = sockfd;
//          exit(0);
		}
	}
	if (i > 0) {
		serve(sockfds, i);		/* new serve */
	} else {
		printf("no sockfds\n");
	}
	exit(1);
}
