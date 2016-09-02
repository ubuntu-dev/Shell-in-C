#include "lib.h"
#include "builtin.h"
#include "helper.h"


int yash_start(char **args)
{
	pid_t pid,wpid;

	int stat,i,f;

	pid = fork();
	if (pid == 0) {
		i=0;
		while(args[i]!=NULL)
		{
			if(strcmp(args[i],"&")==0)
			{
				f=1;
				args[i]=NULL;
				break;
			}
			i+=1;
		}
		
		if (execvp(args[0], args) == -1) {
			perror("yash");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		perror("yash");
	} else {
		i=0;
		while(args[i]!=NULL)
		{
			if(strcmp(args[i],"&")==0)
			{
				printf("%d\n",pid);
				f=1;
				args[i]=NULL;
				break;
			}
			i+=1;
		}

		if(!f)
			wpid=waitpid(pid,&stat,0);
	}

	return 1;
}
