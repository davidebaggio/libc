#include "base64.h"

char base64_encode_char(char c)
{
	if (c >= 0 && c <= 25)
	{
		return 'A' + c;
	}
	else if (c >= 26 && c <= 51)
	{
		return 'a' + (c - 26);
	}
	else if (c >= 52 && c <= 61)
	{
		return '0' + (c - 52);
	}
	else if (c == 62)
	{
		return '+';
	}
	else
	{
		return '/';
	}
}

char *base64_encode(unsigned char *input, size_t input_len)
{
	size_t output_len = ((input_len + 2) / 3) * 4;
	char *output = (char *)malloc(output_len + 1);

	size_t i, j;
	for (i = 0, j = 0; i < input_len; i += 3, j += 4)
	{
		unsigned char chunk[3];
		char encoded_chunk[4];

		chunk[0] = input[i];
		if (i + 1 < input_len)
		{
			chunk[1] = input[i + 1];
		}
		else
		{
			chunk[1] = 0;
		}
		if (i + 2 < input_len)
		{
			chunk[2] = input[i + 2];
		}
		else
		{
			chunk[2] = 0;
		}

		encoded_chunk[0] = base64_encode_char(chunk[0] >> 2);
		encoded_chunk[1] = base64_encode_char(((chunk[0] & 0x3) << 4) | (chunk[1] >> 4));
		encoded_chunk[2] = base64_encode_char(((chunk[1] & 0xF) << 2) | (chunk[2] >> 6));
		encoded_chunk[3] = base64_encode_char(chunk[2] & 0x3F);

		if (i + 1 >= input_len)
		{
			encoded_chunk[2] = '=';
		}
		if (i + 2 >= input_len)
		{
			encoded_chunk[3] = '=';
		}

		memcpy(output + j, encoded_chunk, 4);
	}

	output[output_len] = '\0';
	return output;
}