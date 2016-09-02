#include "lib.h"
#include "builtin.h"
#include "helper.h"

int yash_pwd(char **arg)
{
	char p[110];
	getcwd(p,110);
	printf("%s\n",p);
	return 1;
}
