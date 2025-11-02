#ifndef DB_HEADER_H
#define DB_HEADER_H

#include <stdint.h>

typedef struct {
    char signature[4];
    uint32_t tx_count;
    uint32_t num_structs;
    uint32_t checksum;
} DBHeader;

#endif