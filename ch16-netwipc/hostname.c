#include <common.h>

int main(int argc, const char *argv[])
{
	char name[100];
	chk_nega(gethostname(name, 100));
	printf("%s\n", name);
	return 0;
}
