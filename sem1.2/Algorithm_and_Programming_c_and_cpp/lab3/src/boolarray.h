#pragma once
#include<iostream>

class BoolArray {
private:
    unsigned char* data;//storage array for bits
    size_t bit_count;//logical size in bits
    size_t bit_capacity;//allocated capacity in bits

    size_t bytes_needed(size_t bits) const;
    void set_bit(size_t index, bool value);
    bool get_bit(size_t index) const;
    void ensure_capacity(size_t new_capacity_bits);

public:
    //proxy class: allows accessing and modifying bits using []
    class BitRef {
        BoolArray& array;
        size_t index;
    public:
        BitRef(BoolArray& arr, size_t idx);
        operator bool() const;
        BitRef& operator=(bool value);
        BitRef& operator=(const BitRef& other);
    };

    BoolArray(size_t size, bool initial_value = false);
    BoolArray(const BoolArray& other);
    ~BoolArray();
    
    BitRef operator[](size_t index);
    bool operator[](size_t index) const;
    void resize(size_t new_size, bool fill_value = false);
    size_t size() const;

    void print() const;
};
