#include "boolarray.h"

//calculate the number of bytes required to store the given number of bits
size_t BoolArray::bytes_needed(size_t bits) const {
    return (bits + 7) / 8;//round up to byte
}

//set the bit at the given index to the specified value(true or false)
void BoolArray::set_bit(size_t index, bool value) {
    size_t byte_idx = index / 8;
    size_t bit_idx = index % 8;
    if (value) {
        data[byte_idx] |= (1 << bit_idx);//set bit to 1
    } else {
        data[byte_idx] &= ~(1 << bit_idx);//set bit to 0
    }
}

//get the value of the bit at the given index
bool BoolArray::get_bit(size_t index) const {
    size_t byte_idx = index / 8;
    size_t bit_idx = index % 8;
    return (data[byte_idx] >> bit_idx) & 1;
}

//ensure there is enough space for the new capacity in bits
void BoolArray::ensure_capacity(size_t new_capacity_bits) {
    if (new_capacity_bits <= bit_capacity) return;
    size_t new_bytes = bytes_needed(new_capacity_bits);
    unsigned char* new_data = new unsigned char[new_bytes] {};//initialize with 0s
    if (data) {
        for (size_t i = 0; i < bytes_needed(bit_capacity); ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
    }
    data = new_data;
    bit_capacity = new_capacity_bits;
}

//constructor for BitRef class
BoolArray::BitRef::BitRef(BoolArray& arr, size_t idx)
    : array(arr), index(idx) {}

//convert BitRef to bool for reading
BoolArray::BitRef::operator bool() const {
    return array.get_bit(index);
}

//set the bit value via BitRef
BoolArray::BitRef& BoolArray::BitRef::operator=(bool value) {
    array.set_bit(index, value);
    return *this;
}

//assign the value of another BitRef
BoolArray::BitRef& BoolArray::BitRef::operator=(const BitRef& other) {
    array.set_bit(index, static_cast<bool>(other));
    return *this;
}

//constructor for BoolArray
BoolArray::BoolArray(size_t size, bool initial_value)
    : data(nullptr), bit_count(size), bit_capacity(0) {
    ensure_capacity(size);
    for (size_t i = 0; i < size; ++i) {
        set_bit(i, initial_value);
    }
}

//copy constructor for BoolArray
BoolArray::BoolArray(const BoolArray& other)
    : data(nullptr), bit_count(other.bit_count), bit_capacity(0) {
    ensure_capacity(other.bit_count);
    for (size_t i = 0; i < bytes_needed(bit_count); ++i) {
        data[i] = other.data[i];
    }
}

//destructor for BoolArray
BoolArray::~BoolArray() {
    delete[] data;
}

//overloaded [] operator to return a proxy for modifying bits
BoolArray::BitRef BoolArray::operator[](size_t index) {
    return BitRef(*this, index);
}

//overloaded [] operator for reading bits
bool BoolArray::operator[](size_t index) const {
    return get_bit(index);
}

//resize the BoolArray, with optional fill value for new bits
void BoolArray::resize(size_t new_size, bool fill_value) {
    if (new_size > bit_count) {
        ensure_capacity(new_size);
        for (size_t i = bit_count; i < new_size; ++i) {
            set_bit(i, fill_value);
        }
    }
    bit_count = new_size;
}

//return the number of bits in the array
size_t BoolArray::size() const {
    return bit_count;
}

//print 
void BoolArray::print() const {
    std::cout << "[";
    for (size_t i = 0; i < bit_count; ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << (get_bit(i) ? "true" : "false");
    }
    std::cout << "]" << std::endl;
}
