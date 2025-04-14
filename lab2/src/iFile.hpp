#pragma once
#include <cstddef>

class iFile {
public:
    virtual bool can_read() const = 0;
    virtual bool can_write() const = 0;
    virtual void read(void* buf, size_t max_bytes) = 0;
    virtual void write(const void* buf, size_t n_bytes) = 0;

    virtual ~iFile() {}
};
