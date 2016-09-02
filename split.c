#include "lib.h"
#include "builtin.h"
#include "helper.h"

#define YASH_TOK_BUFSIZE 64
#define YASH_TOK_DELIM " \t\r\n\a"
char **yash_split_line(char *line)
{
	int bufsize = YASH_TOK_BUFSIZE, pos = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token, **tokens_bk;

	if (!tokens) {
		fprintf(stderr, "yash: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, YASH_TOK_DELIM);
	while (token != NULL) {
		tokens[pos] = token;
		pos++;

		if (pos >= bufsize) {
			bufsize += YASH_TOK_BUFSIZE;
			tokens_bk = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens) {
				free(tokens_bk);
				fprintf(stderr, "yash: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, YASH_TOK_DELIM);
	}
	tokens[pos] = NULL;
	return tokens;
}
