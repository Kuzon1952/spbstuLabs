#include "rlefile2.hpp"
#include <iostream>

RleFile2::RleFile2(iFile* f) : inner(f) {}

RleFile2::~RleFile2() {
    //delete inner;  
}

bool RleFile2::can_read() const {
    return inner->can_read();//delegate to inner file object
}


bool RleFile2::can_write() const {
    return inner->can_write(); 
}

size_t RleFile2::write(const void* buf, size_t n_bytes) {
    return inner->write(buf, n_bytes); 
}

size_t RleFile2::read(void* buf, size_t max_bytes) {
    return inner->read(buf, max_bytes);  

}