#define FD_SETSIZE 2048
#include <common.h>

int main(int argc, const char *argv[])
{
	printf("%d\n", FD_SETSIZE);
	return 0;
}
