#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <string.h>
#include <sys/utsname.h>

int yash_cd(char **args);
int yash_pwd(char **args);
int yash_exit(char **args);
int yash_echo(char **args);



