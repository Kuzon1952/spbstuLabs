#ifndef BASE32FILE2_HPP
#define BASE32FILE2_HPP

#include "iFile.hpp"
#include <cstring>

class Base32File2 : public iFile {
private:
    iFile* inner;
    const char* encodingTable;
    int encodingTableSize;

    int encode32(const char* raw_data, int raw_size, char* dst);
    int decode32(const char* encoded_data, int encoded_size, char* dst);
    int encoded32_size(int raw_size);

public:
    Base32File2(iFile* innerFile, const char* table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456");
    ~Base32File2();

    bool can_read() const override;
    bool can_write() const override;
    void write(const void* buf, size_t n_bytes) override;
    void read(void* buf, size_t max_bytes) override;
};

#endif
