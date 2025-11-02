#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "route.h"
#include "db_header.h"
#include <stdint.h>
#include <zlib.h>

int write_database(const char *filename, DBHeader *header, ROUTE *routes, size_t n);
int read_database(const char *filename, DBHeader *header, ROUTE **routes);
uint32_t compute_crc32(ROUTE *routes, size_t count);

#endif