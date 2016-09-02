#include "lib.h"
#include "builtin.h"
#include "helper.h"

int yash_cd(char **args)
{
	if (args[1] == NULL) {
		fprintf(stderr, "yash: expected argument to \"cd\"\n");
	} else {
		if (chdir(args[1]) != 0) {
			perror("yash");
		}
	}
	return 1;
}
