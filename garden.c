#include <stdio.h>
#include <stdlib.h>

#include <dirent.h> 		/* readdir, opendir */
#include <sys/types.h>		/* opendir */

int
dir_print(char *dirname)
{
	struct dirent *dirent;
	int isdir = 0;		/* TODO 1: properly set this! */
	DIR *d;

	d = opendir(dirname);
	if (!d) return -1;

	dirent = readdir(d);
	if (!dirent) return -1;

	printf("%s: [%s, type = %s]\n",
	       dirname, dirent->d_name,
	       isdir ? "directory" : "file");

	/* TODO 2: go through the entire directory and investigate each file/directory */

	/* TODO 3: print a properly indented tree as in the `tree` command. Note, this is a DFS. */

	/* TODO 4: I want *ornate* trees!!! print out the first 16 bytes of each file to give the tree *danglies*! */

	return 0;
}

int
main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s <dirname>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (dir_print(argv[1]) != 0) {
		printf("Could not print directory %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return 0;
}
