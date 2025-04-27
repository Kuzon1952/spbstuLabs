#include "rlefile2.hpp"
#include <iostream>

RleFile2::RleFile2(iFile* f) : inner(f) {}

RleFile2::~RleFile2() {
    delete inner;
}

bool RleFile2::can_read() const {
    return inner->can_read();
}

bool RleFile2::can_write() const {
    return inner->can_write();
}

void RleFile2::write(const void* buf, size_t n_bytes) {
    const unsigned char* data = static_cast<const unsigned char*>(buf);
    size_t i = 0;

    while (i < n_bytes) {
        unsigned char ch = data[i];
        unsigned char count = 1;

        while (i + count < n_bytes && data[i + count] == ch && count < 255) {
            count++;
        }

        unsigned char pair[2] = { count, ch };
        inner->write(pair, 2);
        i += count;
    }
}

void RleFile2::read(void* buf, size_t max_bytes) {
    unsigned char* out = static_cast<unsigned char*>(buf);
    size_t pos = 0;

    while (pos < max_bytes) {
        unsigned char pair[2];
        inner->read(pair, 2);
        for (int j = 0; j < pair[0] && pos < max_bytes; ++j) {
            out[pos++] = pair[1];
        }
    }
}
