#ifndef LBENDIAN_H
#define LBENDIAN_H

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

bool is_little_endian();
bool is_big_endian();

#define SIZE16 sizeof(uint16_t)
#define SIZE32 sizeof(uint32_t)
#define SIZE64 sizeof(uint64_t)

uint16_t hton16(uint16_t);
uint32_t hton32(uint32_t);
uint64_t hton64(uint64_t);
uint16_t ntoh16(uint16_t);
uint32_t ntoh32(uint32_t);
uint64_t ntoh64(uint64_t);

#endif