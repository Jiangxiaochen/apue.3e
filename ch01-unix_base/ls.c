#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
	DIR *dp;
	struct dirent *dirp;
	if (argc != 2) {
		fprintf(stderr,"usage: ls dir");
		return -1;
	}
	if ((dp = opendir(argv[1])) == NULL) {
		fprintf(stderr,"can't open %s", argv[1]);
		return -2;
	}
	while ((dirp = readdir(dp)) != NULL) {
		printf("%s\n", dirp->d_name);
	}
	closedir(dp);
	int a;
	scanf("%d", &a);
	switch(a)
	{
		case 1:
			printf("a is 1");
			break;
		case 2:
			printf("a is 2");
			break;
		case 3:
			printf("a is 3");
			break;
		default:
			printf("default");
			break;
	}
	return 0;
}
