#include <stdio.h>
#include "lbendian.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	if (is_little_endian())
		printf("Little endian\n");
	else
		printf("Big endian\n");
	return 0;
}
