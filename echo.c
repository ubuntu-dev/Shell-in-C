#include "lib.h"
#include "builtin.h"
#include "helper.h"

int yash_echo(char **arg)
{
	int x=1;
	while(arg[x]!=NULL)
	{	
		printf("%s",arg[x]);
		x++;
	}
	printf("\n");

	return 1;
}
