#ifndef RLEFILE2_HPP
#define RLEFILE2_HPP

#include "iFile.hpp"

class RleFile2 : public iFile {
private:
    iFile* inner;

public:
    explicit RleFile2(iFile* f);   // takes ownership of inner
    ~RleFile2();

    bool can_read() const override;
    bool can_write() const override;
    void write(const void* buf, size_t n_bytes) override;
    void read(void* buf, size_t max_bytes) override;
};

#endif
