#include "base32file.hpp"

using namespace std;

//constructor
Base32File::Base32File(const char* path, const char* mode, const char* table) 
    : BaseFile(path, mode), encodingTable(table), encodingTableSize(static_cast<int>(strlen(table))), decodeBufferPos(0), decodeBufferSize(0), eofReached(false) {
    cout << "constructor with file path and mode called from Base32File" << endl;
}

//destructor
Base32File::~Base32File() {
    cout<<"destructor called from Base32File"<<endl;
    
}


int Base32File::encoded32_size(int raw_size) {//calculating encoded data size
    return ((raw_size + 4) / 5) * 8; 
}

int Base32File::decoded32_size(int encoded_size) {//calculating decoded data size
    return (encoded_size * 5 + 7) / 8; 
}


int Base32File::encode32(const char* raw_data, int raw_size, char* dst) {//encoding function
    if (raw_data == nullptr || dst == nullptr || raw_size < 0) {
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
    
    
    if (bit_count > 0) {//handleing remaining bits
        int index = (buffer << (5 - bit_count)) & 31;
        dst[idx++] = encodingTable[index];
    }
    
    
    while (idx % 8 != 0) {//padding if nedded
        dst[idx++] = '=';
    }
    
    dst[idx] = '\0';
    return 0;
}

int Base32File::decode32(const char* encoded_data, int encoded_size, char* dst) {//decoding function
    if (encoded_data == nullptr || dst == nullptr || encoded_size < 0) return -1;

    unsigned int buffer = 0;
    int bit_count = 0;
    int idx = 0;

    for (int i = 0; i < encoded_size; ++i) {
        char c = encoded_data[i];
        if (c == '=') break;

        int value = -1;
        for (int j = 0; j < encodingTableSize; ++j) {
            if (encodingTable[j] == c) {
                value = j;
                break;
            }
        }

        if (value == -1) return -1;//invalid character

        buffer = (buffer << 5) | value;
        bit_count += 5;

        if (bit_count >= 8) {
            dst[idx++] = (buffer >> (bit_count - 8)) & 0xFF;
            bit_count -= 8;
        }
    }

    return idx;
}


size_t Base32File::write(const void* buf, size_t n_bytes) {
    if (n_bytes == 0) return 0;
    
    
    int encoded_size = encoded32_size(n_bytes);//calculation for size and stack allocation
    char* encoded = new char[encoded_size + 1];
    
    if (encode32(static_cast<const char*>(buf), n_bytes, encoded) != 0){
        delete[] encoded;
        return 0;
    }
    
    size_t written = BaseFile::write(encoded, strlen(encoded));
    delete[] encoded;
    return written;
}

size_t Base32File::read(void* buf, size_t max_bytes) {
    if (max_bytes == 0 || eofReached) return 0;

    size_t totalCopied = 0;
    char* output = static_cast<char*>(buf);

    while (totalCopied < max_bytes) { //working untill we have read reqted bytes or hit eof
        
        if (decodeBufferPos < decodeBufferSize) {//if we have decoded data avalable
            size_t available = decodeBufferSize - decodeBufferPos;
            //how much we can cpy
            size_t toCopy = available;
            if (toCopy > max_bytes - totalCopied) {
                toCopy = max_bytes - totalCopied;
            }
            
            memcpy(output + totalCopied, decodeBuffer + decodeBufferPos, toCopy); //copint data to output buffer
            decodeBufferPos += toCopy;
            totalCopied += toCopy;
            
            if (totalCopied >= max_bytes) break;//if done exit
        }

        //need to read and decode more data
        char encodedBuffer[512];
        size_t bytesRead = BaseFile::read(encodedBuffer, sizeof(encodedBuffer) - 1);//reading data frm basefile
        
        if (bytesRead == 0){//eof
            eofReached = true;
            break;
        }

        decodeBufferSize = decode32(encodedBuffer, bytesRead, decodeBuffer);//decode
        if (decodeBufferSize <= 0){//error
            eofReached = true;
            break;
        }
        
        decodeBufferPos = 0;
    }

    return totalCopied;
}


