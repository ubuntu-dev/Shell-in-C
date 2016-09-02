#include "lib.h"
#include "builtin.h"
#include "helper.h"

char home[100];

int main(int argc, char **argv)
{
	yash_loop();
	return EXIT_SUCCESS;
}
