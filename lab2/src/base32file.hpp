#ifndef BASE32FILE_HPP
#define BASE32FILE_HPP

#include "basefile.hpp"
#include <iostream>
#include <cstring>

using namespace std;

class Base32File : public BaseFile {
private:
    const char* encodingTable;//encoding table (default: "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456")
    int encodingTableSize;//size of the encoding table

    int encode32(const char* raw_data, int raw_size, char* dst);
    int decode32(const char* encoded_data, int encoded_size, char* dst);
    int encoded32_size(int raw_size);
    int decoded32_size(int encoded_size);

public:
    Base32File(const char* path, const char* mode, const char* table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456");

    size_t write(const void* buf, size_t n_bytes) override;
    size_t  read(void* buf, size_t max_bytes) override;

    ~Base32File() override;
};

#endif