#include "base32file.hpp"

using namespace std;

//constructor
Base32File::Base32File(const char* path, const char* mode, const char* table) : BaseFile(path, mode), encodingTable(table), encodingTableSize(static_cast<int>(strlen(table))) {
    cout<<"constructor with file path and mode called from Base32File"<<endl;
}  

//destructor
Base32File::~Base32File() {
    cout<<"destructor called from Base32File"<<endl;
    
}


int Base32File::encoded32_size(int raw_size) {//calculating encoded data size
    return ((raw_size * 8 + 4) / 5);
}


int Base32File::decoded32_size(int encoded_size) {//calculating decoded data size
    return (encoded_size * 5) / 8;
}


int Base32File::encode32(const char* raw_data, int raw_size, char* dst) {//encoding function
    if (raw_data == nullptr || dst == nullptr || raw_size < 0){
        return 1;//error
    } 

    int bit_count = 0;
    unsigned int buffer = 0;
    int idx = 0;

    for (int i = 0; i < raw_size; ++i) {
        buffer = (buffer << 8) | (unsigned char)raw_data[i];
        bit_count += 8;

        while (bit_count >= 5) {
            int index = (buffer >> (bit_count - 5)) & 31;
            dst[idx++] = encodingTable[index];//using encodingTable
            bit_count -= 5;
        }
    }

    if (bit_count > 0) {
        dst[idx++] = encodingTable[0];//padding with 'A'
    }

    dst[idx] = '\0';
    return 0;
}

int Base32File::decode32(const char* encoded_data, int encoded_size, char* dst) {//decoding function
    if (encoded_data == nullptr || dst == nullptr || encoded_size < 0) return 1;

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

        if (value == -1) return 1;//invalid character

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


size_t Base32File::write(const void* buf, size_t n_bytes) {
    char encoded_data[encoded32_size(n_bytes) + 1];
    encode32(static_cast<const char*>(buf), n_bytes, encoded_data);
    size_t bytes_written = BaseFile::write(encoded_data, encoded32_size(n_bytes));

    return bytes_written;
}

size_t Base32File::read(void* buf, size_t max_bytes) {
    //temp buf
    char buffer[256];
    size_t bytes_read = BaseFile::read(buffer, sizeof(buffer) - 1);  

    if (bytes_read == 0) {
        return 0;  // eof or error
    }

    //decode 
    char decoded_data[decoded32_size(bytes_read) + 1];
    decode32(buffer, bytes_read, decoded_data);

    //copy the decoded data to the provided buffer, making sure we don't exceed max_bytes
    size_t bytes_to_copy = std::min(static_cast<size_t>(decoded32_size(bytes_read)), max_bytes);
    strncpy(static_cast<char*>(buf), decoded_data, bytes_to_copy);

    return bytes_to_copy;  
}
