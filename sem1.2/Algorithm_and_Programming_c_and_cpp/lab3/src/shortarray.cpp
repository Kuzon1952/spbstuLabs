#include "shortarray.hpp"
#include <algorithm>//for std::copy

//constructor
ShortArray::ShortArray() : length(0), capacity(INLINE_CAPACITY), memory_info{0, INLINE_CAPACITY} {
    memory_info.is_dynamic = 0;//start with inline storage
}

//destructor 
ShortArray::~ShortArray() {
    if (memory_info.is_dynamic) {
        delete[] storage.dynamic_data;
    }
}

//get(either inline or dynamic)
short* ShortArray::get_data_ptr() {
    if (memory_info.is_dynamic) {
        return storage.dynamic_data;
    } else {
        return storage.inline_data;
    }
}

const short* ShortArray::get_data_ptr() const {
    if (memory_info.is_dynamic) {
        return storage.dynamic_data;
    } else {
        return storage.inline_data;
    }
}

//add an element 
void ShortArray::push(short new_val) {
    if (length == capacity) {
        resize(capacity * 2);
    }
    get_data_ptr()[length++] = new_val;
}

//remove and return the last element
short ShortArray::pop() {
    if (length == 0) {
        throw std::out_of_range("Cannot pop from empty array");
    }
    return get_data_ptr()[--length];
}

//get the size of the array
size_t ShortArray::size() const {
    return length;
}

// Resize the array, increasing the size and filling new slots with `fill_value`
void ShortArray::resize(size_t new_size, short fill_value) {
    short* old_data = get_data_ptr();

    //update arr if shinking
    if (new_size <= capacity && (!memory_info.is_dynamic || new_size <= INLINE_CAPACITY)) {
        for (size_t i = length; i < new_size; ++i) {
            get_data_ptr()[i] = fill_value;
        }
        length = new_size;
        return;
    }

    //allocate new memory
    short* new_data = new short[new_size];

    //copy the old data
    for (size_t i = 0; i < length; ++i) {
        new_data[i] = old_data[i];
    }

    //fill new slots
    for (size_t i = length; i < new_size; ++i) {
        new_data[i] = fill_value;
    }

    
    if (memory_info.is_dynamic) {
        delete[] storage.dynamic_data;
    }

    //assign the new data and update the memory_info
    storage.dynamic_data = new_data;
    memory_info.is_dynamic = 1;//dynamic
    capacity = new_size;
    length = new_size;
}

//access an element(non-const version)
short& ShortArray::operator[](size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return get_data_ptr()[index];
}

//const
const short& ShortArray::operator[](size_t index) const {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return get_data_ptr()[index];
}
