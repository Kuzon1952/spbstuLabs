// shortarray.hpp
#ifndef SHORTARRAY_HPP
#define SHORTARRAY_HPP

#include <cstddef> // for size_t
#include <stdexcept>
#include <iostream>
#include <cstddef>


class ShortArray {
private:
    short* data;
    size_t length;//actual number of elements
    size_t capacity;//allocated memory
    

    static const size_t INLINE_CAPACITY = 12;
    bool is_dynamic;
    union {
        short inline_data[INLINE_CAPACITY];
        short* dynamic_data;
    } storage;

    struct {
        unsigned int is_dynamic : 1;//using the last bit for dynamic check
        unsigned int size : 31; //using the rest of the bits for the size
    } memory_info;

    short* get_data_ptr();
    const short* get_data_ptr() const;
    

public:
    ShortArray();
    ShortArray(const ShortArray& other);
    ~ShortArray();

    void push(short new_val);
    short pop();
    size_t size() const;
    void resize(size_t new_size, short fill_value = 0);

    short& operator[](size_t index);
    const short& operator[](size_t index) const;
};

#endif
