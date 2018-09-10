#include <common.h>
#include <sys/stat.h>
#include <sys/socket.h>

int main(int argc, const char *argv[])
{
	int sockfd;
	chk_nega((sockfd = socket(AF_INET, SOCK_STREAM, 0)));
	struct stat buf;
	chk_nega(fstat(sockfd, &buf));

	printf("%ld\n", (long) buf.st_dev);
	printf("%ld\n", (long) buf.st_ino);
	printf("%ld\n", (long) buf.st_mode);
	printf("%ld\n", (long) buf.st_nlink);
	printf("%ld\n", (long) buf.st_uid);
	printf("%ld\n", (long) buf.st_gid);
	printf("%ld\n", (long) buf.st_rdev);
	printf("%ld\n", (long) buf.st_size);
	printf("%ld\n", (long) buf.st_blksize);
	printf("%ld\n", (long) buf.st_blocks);
	printf("%ld\n", (long) buf.st_atime);
	printf("%ld\n", (long) buf.st_mtime);
	printf("%ld\n", (long) buf.st_ctime);

	return 0;
}
