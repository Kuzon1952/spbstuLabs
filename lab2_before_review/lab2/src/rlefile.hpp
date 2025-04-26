#ifndef RLEFILE_HPP
#define RLEFILE_HPP

#include "basefile.hpp"

class RleFile : public BaseFile {
public:
    using BaseFile::BaseFile;//inherit constructors

    ~RleFile() override;

    void write(const void* buf, size_t n_bytes) override;
    void read(void* buf, size_t max_bytes) override;
};



#endif
