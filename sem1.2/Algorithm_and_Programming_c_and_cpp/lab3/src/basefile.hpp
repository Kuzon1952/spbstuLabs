#ifndef BASEFILE_HPP
#define BASEFILE_HPP

#include <cstdio>
#include <iostream>
using namespace std;

class BaseFile {
protected:
    FILE* file_ptr;
    const char* mode;

public:
    BaseFile();
    BaseFile(const char* path, const char* mode);
    BaseFile(FILE* existing_file_ptr);

    //meleted copy constructor and copy assignment operator
    BaseFile(const BaseFile&) = delete;
    BaseFile& operator=(const BaseFile&) = delete;

    //move constructor and move assignment operator
    BaseFile(BaseFile&& other) noexcept;
    BaseFile& operator=(BaseFile&& other) noexcept;

    ~BaseFile();

    size_t write_raw(const void* buf, size_t n_bytes);
    size_t read_raw(void* buf, size_t max_bytes);
    size_t write(const void* buf, size_t n_bytes);
    size_t read(void* buf, size_t max_bytes);
    bool is_open() const;
    bool can_read() const;
    bool can_write() const;
    long tell() const;
    bool seek(long offset);
    void close();
};

#endif // BASEFILE_HPP