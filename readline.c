#include "lib.h"
#include "builtin.h"
#include "helper.h"

#define YASH_RL_BUFSIZE 1024
char *yash_read_line(void)
{
	int bufsize = YASH_RL_BUFSIZE;
	int pos = 0;
	char *buff = malloc(sizeof(char) * bufsize);
	int c;

	if (!buff) {
		fprintf(stderr, "yash: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1) {
		c = getchar();
		if (c == EOF || c == '\n') {
			buff[pos] = '\0';
			return buff;
		} else {
			buff[pos] = c;
		}
		pos++;

		if (pos >= bufsize) {
			bufsize += YASH_RL_BUFSIZE;
			buff = realloc(buff, bufsize);
			if (!buff) {
				fprintf(stderr, "yash: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
