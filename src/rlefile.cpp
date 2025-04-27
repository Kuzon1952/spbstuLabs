
#include "rlefile.hpp"
#include <iostream>

RleFile::RleFile(const char* path, const char* mode) 
    : BaseFile(path, mode), leftover_count(0) {
    // Initialize leftover buffer to zeros
    memset(leftover_buffer, 0, sizeof(leftover_buffer));
}

size_t RleFile::write(const void* buf, size_t n_bytes) {
    if (!file_ptr || !buf) return 0;//return 0 if file is not open or buffer is null

    const unsigned char* data = static_cast<const unsigned char*>(buf);//cast to byte array
    size_t i = 0;  
    size_t total_bytes_written = 0; 

    while (i < n_bytes) {  
        unsigned char ch = data[i];  
        unsigned char count = 1;  

        //count the number of consecutive repeated characters
        while (i + count < n_bytes && data[i + count] == ch && count < 255) {
            count++;  
        }

        unsigned char pair[2] = { count, ch };//pair: count and char
        size_t bytes_written = fwrite(pair, 1, 2, file_ptr);  
        if (bytes_written < 2) {
            std::cerr << "error writing to file" << std::endl;
            return total_bytes_written;  
        }
        total_bytes_written += bytes_written; //add the number of bytes written

        i += count; 
    }

    return total_bytes_written;  
}
size_t RleFile::read(void* buf, size_t max_bytes) {
    if (!file_ptr || !buf) return 0;  

    unsigned char* out = static_cast<unsigned char*>(buf);  
    size_t pos = 0; 
    size_t total_bytes_read = 0;  
   

    //ff there's leftover data, process it first
    if (leftover_count > 0) {
        size_t bytes_to_copy = std::min(leftover_count, max_bytes);
        std::memcpy(out, leftover_buffer, bytes_to_copy);
        pos += bytes_to_copy;
        total_bytes_read += bytes_to_copy;

        //move leftover data
        leftover_count -= bytes_to_copy;
        std::memmove(leftover_buffer, leftover_buffer + bytes_to_copy, leftover_count);
    }

    
    while (pos < max_bytes) {
        unsigned char pair[2];  
        if (fread(pair, 1, 2, file_ptr) < 2) break;//stop if less than 2 bytes are read

        //if there’s more data than can fit in the buffer, save the leftovers
        if (pair[0] + pos > max_bytes) {
            size_t remaining_space = max_bytes - pos;
            size_t leftover_size = pair[0] - remaining_space;
            leftover_count = leftover_size;
            std::memcpy(leftover_buffer, pair + 1 + remaining_space, leftover_count);//save the leftover characters

            //copy as much data as will fit into the buffer
            for (size_t j = 0; j < remaining_space; ++j) {
                out[pos++] = pair[1];
                total_bytes_read++;
            }
        } else {
            //otherwise, fit all the data in the current buffer
            for (int j = 0; j < pair[0]; ++j) {
                out[pos++] = pair[1];
                total_bytes_read++;
            }
        }
    }

    return total_bytes_read; 
}


RleFile::~RleFile() {
    
    std::cout << "destructor called for RleFile" << std::endl;
    
}