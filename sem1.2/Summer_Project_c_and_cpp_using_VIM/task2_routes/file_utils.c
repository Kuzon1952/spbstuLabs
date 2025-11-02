#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int write_database(const char *filename, DBHeader *header, ROUTE *routes, size_t n) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) return -1;

    header->num_structs = n;
    header->checksum = compute_crc32(routes, n);
    header->tx_count += 1;

    fwrite(header, sizeof(DBHeader), 1, fp);
    fwrite(routes, sizeof(ROUTE), n, fp);

    fclose(fp);
    return 0;
}

int read_database(const char *filename, DBHeader *header, ROUTE **routes) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return -1;

    fread(header, sizeof(DBHeader), 1, fp);
    header->tx_count += 1;

    *routes = malloc(sizeof(ROUTE) * header->num_structs);
    if (!*routes) {
        fclose(fp);
        return -2;
    }

    fread(*routes, sizeof(ROUTE), header->num_structs, fp);
    fclose(fp);

    return 0;
}

uint32_t compute_crc32(ROUTE *routes, size_t count) {
    return crc32(0L, (const Bytef *)routes, sizeof(ROUTE) * count);
}