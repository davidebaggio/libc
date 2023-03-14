#include "lbendian.h"

bool is_little_endian()
{
	uint16_t number = 513;
	char *p = (char *)&number;
	if (p[0] == 1)
		return true;
	else
		return false;
}

bool is_big_endian()
{
	return !is_little_endian();
}

uint16_t hton16(uint16_t host16)
{
	if (is_big_endian())
		return host16;
	uint8_t bytes[SIZE16];
	uint8_t *p = (uint8_t *)&host16;
	for (size_t i = 0; i < SIZE16; i++)
	{
		bytes[i] = p[SIZE16 - 1 - i];
		// printf("%d\n", bytes[i]);
	}
	uint16_t *q = (uint16_t *)&bytes;
	return *q;
}

uint32_t hton32(uint32_t host32)
{
	if (is_big_endian())
		return host32;
	uint8_t bytes[SIZE32];
	uint8_t *p = (uint8_t *)&host32;
	for (size_t i = 0; i < SIZE32; i++)
	{
		bytes[i] = p[SIZE32 - 1 - i];
		// printf("%d\n", bytes[i]);
	}
	uint32_t *q = (uint32_t *)&bytes;
	return *q;
}

uint64_t hton64(uint64_t host64)
{
	if (is_big_endian())
		return host64;
	uint8_t bytes[SIZE64];
	uint8_t *p = (uint8_t *)&host64;
	for (size_t i = 0; i < SIZE64; i++)
	{
		bytes[i] = p[SIZE64 - 1 - i];
		// printf("%d\n", bytes[i]);
	}
	uint64_t *q = (uint64_t *)&bytes;
	return *q;
}

uint16_t ntoh16(uint16_t net16)
{
	return hton16(net16);
}

uint32_t ntoh32(uint32_t net32)
{
	return hton32(net32);
}

uint64_t ntoh64(uint64_t net64)
{
	return hton64(net64);
}
