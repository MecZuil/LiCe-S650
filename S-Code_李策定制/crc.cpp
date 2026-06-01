#include "crc.h"

int crc32_calculate(unsigned int crc32_value, void *buffer, unsigned int size)
{
    unsigned int i;
    unsigned char *pt = (unsigned char *) buffer;

    for (i = 0; i < size; i++) {
        crc32_value = crc_table[(crc32_value ^ *pt) & 0xff] ^ (crc32_value >> 8);
        pt++;
    }

    return crc32_value;
}
