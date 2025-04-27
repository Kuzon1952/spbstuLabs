#include "rlefile.hpp"

void RleFile::write(const void* buf, size_t n_bytes) {
    if (!file_ptr || !buf) return;//file is not open or buffer is null stop.

    const unsigned char* data = static_cast<const unsigned char*>(buf);//cast to byte arr
    size_t i = 0;//start idx

    while (i < n_bytes) {//loop untill end of data
        unsigned char ch = data[i];//current char
        unsigned char count = 1;//initialize repeat count to 1

        while (i + count < n_bytes && data[i + count] == ch && count < 255) {//how many times the char is repeated
            count++;//increase 
        }

        unsigned char pair[2] = { count, ch };
        fwrite(pair, 1, 2, file_ptr);//write 2bytes: count and char

        i += count;//moving forward 
    }
}

void RleFile::read(void* buf, size_t max_bytes) {
    if (!file_ptr || !buf) return;//file is not open or buffer is null stop.

    unsigned char* out = static_cast<unsigned char*>(buf);//cast to byte arr
    size_t pos = 0;//current position

    while (pos < max_bytes) {//loop untill end of data
        unsigned char pair[2];//temp for count and char
        if (fread(pair, 1, 2, file_ptr) < 2) break;//stop if less than 2 bytes

        for (int j = 0; j < pair[0] && pos < max_bytes; ++j) {
            out[pos++] = pair[1];//fill buffer with repeated chars
        }
    }
}

RleFile::~RleFile() {
    cout<<"destructor called from RleFile"<<endl;
}
