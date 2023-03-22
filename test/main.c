#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "lbendian.h"

int main(int argc, const char *argv[])
{
	(void)argc;
	(void)argv;
	if (is_little_endian())
		printf("Little endian\n\n");
	else
		printf("Big endian\n\n");

	srand(time(NULL));
	int n = rand() % 3;
	if (n == 0)
	{
		uint16_t number = 513;
		uint16_t conv16 = hton16(number);
		printf("Conversion from host to network 2bytes %u --> %u\n", number, conv16);
		printf("Conversion from network to host 2bytes %u --> %u\n\n", conv16, ntoh16(conv16));
	}
	else if (n == 1)
	{
		uint32_t number = 513;
		uint32_t conv32 = hton32(number);
		printf("Conversion from host to network 4bytes %u --> %u\n", number, conv32);
		printf("Conversion from network to host 4bytes %u --> %u\n\n", conv32, ntoh32(conv32));
	}
	else
	{
		uint64_t number = 513;
		uint64_t conv64 = hton64(number);
		printf("Conversion from host to network 8bytes %u --> %u\n", number, conv64);
		printf("Conversion from network to host 8bytes %u --> %u\n", conv64, ntoh64(conv64));
	}
	return 0;
}
