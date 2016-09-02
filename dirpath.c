#include "lib.h"
#include "builtin.h"
#include "helper.h"
char *replace_str(char *str, char *orig, char *rep)
{
	static char buff[4096];
	char *p;

	if(!(p = strstr(str, orig)))  // Is 'orig' even in 'str'?
	{
		strcpy(buff,str);
		return buff;
	} 

	strncpy(buff, str, p-str); // Copy characters from 'str' start to 'orig' st$
	buff[p-str] = '\0';

	sprintf(buff+(p-str), "%s%s", rep, p+strlen(orig));

	return buff;
}
