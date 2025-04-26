#pragma once
#include "iFile.hpp"
#ifndef BASEFILE_HPP
#define BASEFILE_HPP

#include <iostream>//for File: fopen, fcluse, fread, fwrite...
#include <cstring>//for strlen, strcpy, etc.
#include <cstdio>
#include <string>

using namespace std;

class BaseFile : public iFile {
    protected:
        FILE* file_ptr;//pointer to the file
        const char* mode;
    
    public:
        BaseFile();//default constructor
        BaseFile(const char* path, const char* mode);//constructor with file path and mode
        BaseFile(FILE* existing_file_ptr);//pointer constructor 

        virtual ~BaseFile();//destructor

        bool is_open() const;//checking if the file is open
        bool can_read() const;//checking if the file can be read
        bool can_write() const;//checking if the file can be written to
        size_t write_raw(const void* buf, size_t n_bytes);//writing raw data to the file
        size_t read_raw(void* buf, size_t max_bytes);//reading raw data from the file
        long tell() const;//getting current file position
        bool seek(long offset);//setting file position

        virtual size_t write(const void* buf, size_t n_bytes);//writing data to the file
        virtual size_t read(void* buf, size_t max_bytes);//reading data from the file
        void close();//closing the file
        
};

#endif