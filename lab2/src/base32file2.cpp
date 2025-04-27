#include "base32file2.hpp"
#include <iostream>

Base32File2::Base32File2(iFile* innerFile, const char* table)
    : inner(innerFile), encodingTable(table), encodingTableSize(strlen(table)) {}

Base32File2::~Base32File2() {
    delete inner;
}

bool Base32File2::can_read() const {
    return inner->can_read();
}

bool Base32File2::can_write() const {
    return inner->can_write();
}

int Base32File2::encoded32_size(int raw_size) {
    return ((raw_size * 8 + 4) / 5);
}

int Base32File2::encode32(const char* raw_data, int raw_size, char* dst) {
    if (!raw_data || !dst || raw_size < 0) return 1;

    int bit_count = 0;
    unsigned int buffer = 0;
    int idx = 0;

    for (int i = 0; i < raw_size; ++i) {
        buffer = (buffer << 8) | (unsigned char)raw_data[i];
        bit_count += 8;

        while (bit_count >= 5) {
            int index = (buffer >> (bit_count - 5)) & 31;
            dst[idx++] = encodingTable[index];
            bit_count -= 5;
        }
    }

    if (bit_count > 0) {
        dst[idx++] = encodingTable[0];  // padding
    }

    dst[idx] = '\0';
    return 0;
}

int Base32File2::decode32(const char* encoded_data, int encoded_size, char* dst) {
    if (!encoded_data || !dst || encoded_size < 0) return 1;

    unsigned int buffer = 0;
    int bit_count = 0;
    int idx = 0;

    for (int i = 0; i < encoded_size; ++i) {
        char c = encoded_data[i];
        int value = -1;

        for (int j = 0; j < encodingTableSize; ++j) {
            if (encodingTable[j] == c) {
                value = j;
                break;
            }
        }

        if (value == -1) return 1;

        buffer = (buffer << 5) | value;
        bit_count += 5;

        if (bit_count >= 8) {
            dst[idx++] = (buffer >> (bit_count - 8)) & 0xFF;
            bit_count -= 8;
        }
    }

    dst[idx] = '\0';
    return 0;
}

void Base32File2::write(const void* buf, size_t n_bytes) {
    char encoded[256];
    encode32(static_cast<const char*>(buf), n_bytes, encoded);
    inner->write(encoded, strlen(encoded));
}

void Base32File2::read(void* buf, size_t max_bytes) {
    char encoded[256];
    inner->read(encoded, sizeof(encoded));

    char decoded[256];
    decode32(encoded, strlen(encoded), decoded);
    strncpy(static_cast<char*>(buf), decoded, max_bytes);
}
