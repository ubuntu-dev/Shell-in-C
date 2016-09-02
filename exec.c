#include "lib.h"
#include "builtin.h"
#include "helper.h"

int (*bltin_func[]) (char **) = {
	&yash_cd,
	&yash_echo,
	&yash_pwd,
	&yash_exit
};
char *bltin_str[] = {
	"cd",
	"echo",
	"pwd",
	"exit"
};

int yash_execute(char **args)
{
	int i;

	if (args[0] == NULL) {
		return 1;
	}

	for (i = 0; i < 4; i++) {
		if (strcmp(args[0], bltin_str[i]) == 0) {
			return (*bltin_func[i])(args);
		}
	}

	return yash_start(args);
}
