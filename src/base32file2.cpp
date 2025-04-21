#include "base32file2.hpp"
#include <iostream>

Base32File2::Base32File2(iFile* innerFile, const char* table)
    : inner(innerFile), encodingTable(table), encodingTableSize(strlen(table)) {}

Base32File2::~Base32File2() {
    delete inner;
}


int Base32File2::decoded32_size(int encoded_size) {
    return (encoded_size * 5) / 8;
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

size_t Base32File2::write(const void* buf, size_t n_bytes) {
    size_t chunk_size = 256;//process data in 256-byte chunks
    const char* data = static_cast<const char*>(buf);
    size_t total_bytes_written = 0;

    while (n_bytes > 0) {
        size_t current_chunk_size = (n_bytes < chunk_size) ? n_bytes : chunk_size;
        
        //temporary buffer to store the encoded data
        char encoded_data[encoded32_size(current_chunk_size) + 1];  
        encode32(data, current_chunk_size, encoded_data);
        
        //writing the encoded chunk to the inner file
        size_t bytes_written = inner->write(encoded_data, strlen(encoded_data));
        
        total_bytes_written += bytes_written;
        
        //movig to the next chunk of data
        data += current_chunk_size;
        n_bytes -= current_chunk_size;
    }

    return total_bytes_written; 
}

size_t Base32File2::read(void* buf, size_t max_bytes) {
    size_t chunk_size = 256;//process data in 256-byte chunks
    char buffer[chunk_size];  
    size_t total_bytes_read = 0;

    while (total_bytes_read < max_bytes) {
        
        size_t bytes_read = inner->read(buffer, chunk_size);//use read() here
        
        if (bytes_read == 0) {
            break;//noo more data to read, stop if EOF is reached
        }

        //decoding the chunk
        size_t decoded_size = decoded32_size(bytes_read);//calculating the decoding size
        char* decoded_data = new char[decoded_size + 1];  
        int result = decode32(buffer, bytes_read, decoded_data);
        if (result != 0) {
            std::cout << "Error during Base32 decoding!" << std::endl;
            delete[] decoded_data; 
            return 0;//return 0 if decoding fails
        }

       
        size_t bytes_to_copy = std::min(decoded_size, max_bytes - total_bytes_read);

        //copy the decoded data to the destination buffer
        memcpy(static_cast<char*>(buf) + total_bytes_read, decoded_data, bytes_to_copy);
        total_bytes_read += bytes_to_copy;

        //if not space
        if (total_bytes_read >= max_bytes) {
            break;
        }

        
        delete[] decoded_data;
    }

    //after the read process
    static_cast<char*>(buf)[total_bytes_read] = '\0';

   
    return total_bytes_read;
}
