#include "base64.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <input>\n", argv[0]);
		return 1;
	}

	size_t input_len = strlen(argv[1]);
	unsigned char *input = (unsigned char *)argv[1];

	char *output = base64_encode(input, input_len);

	printf("%s\n", output);
	free(output);

	return 0;
}
