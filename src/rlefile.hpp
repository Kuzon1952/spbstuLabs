#ifndef RLEFILE_HPP
#define RLEFILE_HPP

#include "basefile.hpp"

class RleFile : public BaseFile {
private: 
    unsigned char leftover_buffer[256];
    size_t leftover_count;  
public:
    using BaseFile::BaseFile;//inherit constructors
    RleFile(const char* path, const char* mode);

    ~RleFile() override;

    size_t write(const void* buf, size_t n_bytes) override;
    size_t read(void* buf, size_t max_bytes) override;

    
};



#endif
