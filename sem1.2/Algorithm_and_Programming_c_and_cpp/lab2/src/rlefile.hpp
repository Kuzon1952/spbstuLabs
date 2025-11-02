#ifndef RLEFILE_HPP
#define RLEFILE_HPP

#include "basefile.hpp"

class RleFile : public BaseFile {
public:
    using BaseFile::BaseFile;//inherit constructors

    ~RleFile() override;

    size_t write(const void* buf, size_t n_bytes) override;
    size_t read(void* buf, size_t max_bytes) override;

    
};



#endif
