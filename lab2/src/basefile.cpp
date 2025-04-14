#include "basefile.hpp"

BaseFile::BaseFile():file_ptr(nullptr) {
    //default constructor
    cout<<"default constructor called from Basefile"<<endl;
}

BaseFile::BaseFile(const char* path, const char* mode) {
    //constructor with file path and mode
    file_ptr = fopen(path, mode);
    if (file_ptr == nullptr) {
        cout << "error opening file: " << path << endl;
    }
    cout<<"constructor with file path and mode called from Basefile"<<endl;
}

BaseFile::BaseFile(FILE* existing_file_ptr):file_ptr(existing_file_ptr) {
    //pointer constructor
    if (file_ptr == nullptr) {
        cout << "error: null file pointer" << endl;
    }
    cout<<"pointer constructor called from Basefile"<<endl;
}

BaseFile::~BaseFile() {
    //destructor
    if (file_ptr != nullptr) {
        fclose(file_ptr);
    }
    cout<<"destructor called from Basefile"<<endl;
}

bool BaseFile::is_open() const {
    //checking if the file is open
    return file_ptr != nullptr;
}

bool BaseFile::can_read() const {
    if(file_ptr == nullptr) {
        cout << "error: file not open" << endl;
        return false;
    }   
    return true;
}

bool BaseFile::can_write() const {
    //checking if the file can be written to
    return file_ptr != nullptr;
}

size_t BaseFile::write_raw(const void* buf, size_t n_bytes) {
    //writing raw data to the file
    if (file_ptr == nullptr) {
        cout << "error: file not open" << endl;
        return 0;
    }
    return fwrite(buf, 1, n_bytes, file_ptr);
}

size_t BaseFile::read_raw(void* buf, size_t max_bytes) {
    //reading raw data from the file
    if (file_ptr == nullptr) {
        cout << "error: file not open" << endl;
        return 0;
    }
    return fread(buf, 1, max_bytes, file_ptr);
}

long BaseFile::tell() const {
    //getting current file position
    if (file_ptr == nullptr) {
        cout << "error: file not open" << endl;
        return -1;
    }
    long position = ftell(file_ptr);
    if (position == -1) {
        cout << "error: Failed to retrieve file position." << endl;
    }
    return position;
}

bool BaseFile::seek(long offset) {
    //setting file position
    if (file_ptr == nullptr) {
        cout << "error: file not open" << endl;
        return false;
    }
    return fseek(file_ptr, offset, SEEK_SET) == 0;
}

void BaseFile::write(const void* buf, size_t n_bytes) {
    //writing data to the file
    write_raw(buf, n_bytes);
}

void BaseFile::read(void* buf, size_t max_bytes) {
    //reading data from the file
    read_raw(buf, max_bytes);
}

void BaseFile::close() {
    //closing the file
    if (file_ptr) {
        fclose(file_ptr);
        file_ptr = nullptr;
    }
}
