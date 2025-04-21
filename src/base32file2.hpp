#ifndef BASE32FILE2_HPP
#define BASE32FILE2_HPP

#pragma once
#include "iFile.hpp"
#include <cstring>

class Base32File2 : public iFile {
private:
    iFile* inner;
    const char* encodingTable;
    int encodingTableSize;
    const char* mode;

    int encode32(const char* raw_data, int raw_size, char* dst);
    int decode32(const char* encoded_data, int encoded_size, char* dst);
    

public:
    Base32File2(iFile* innerFile, const char* table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456");
    ~Base32File2();

    bool can_read() const override;
    bool can_write() const override;
    size_t write(const void* buf, size_t n_bytes) override;
    size_t read(void* buf, size_t max_bytes) override;

    int decoded32_size(int encoded_size);
    int encoded32_size(int raw_size);

};

#endif
