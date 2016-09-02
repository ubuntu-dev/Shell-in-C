#include "lib.h"
#include "builtin.h"
#include "helper.h"

extern char home[100];

void yash_loop(void)
{
	register struct passwd *pw;
	register uid_t uid;
	char hostname[1024];
	char dirpath[1024];

	uid = geteuid (); 
	pw = getpwuid (uid);
	hostname[1023] = '\0';
	gethostname(hostname, 1023);
	char *lin,*rl;
	char **arg;
	int stat;
	getcwd(home,100);

	do {
		char pwd[100];
		getcwd(pwd,100);
		printf("<%s@%s:%s>",pw->pw_name,hostname,replace_str(pwd,home,"~"));
		rl=yash_read_line();
		//printf("%s\n",rl);

		while(rl)
		{
			lin= strsep(&rl,";");
			//printf("%s\n",lin);
			arg = yash_split_line(lin);
			//printf("%s\n",arg[0]);
			stat = yash_execute(arg);
		}
		free(rl);
		free(arg);
	} while (stat);
}
