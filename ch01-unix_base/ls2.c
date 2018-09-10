#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
	DIR *dp;
	struct dirent *dirp;
	if ((dp = opendir(".")) == NULL) {
		fprintf(stderr,"can't open %s", ".");
		return -2;
	}
	while ((dirp = readdir(dp)) != NULL) {
		printf("%s\n", dirp->d_name);
	}
	chdir("/root/");
	dp = opendir(".");
	while ((dirp = readdir(dp)) != NULL) {
		printf("%s\n", dirp->d_name);
	}
	closedir(dp);
	return 0;
}
