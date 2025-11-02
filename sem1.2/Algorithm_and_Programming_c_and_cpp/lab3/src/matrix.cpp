#include "matrix.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;

Matrix::Matrix(int n) : rows(n), cols(n) {
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols]{0};//initialize with zeros
        data[i][i] = 1;//identity matrix
    }
}

Matrix::Matrix(int m, int n, double fill_value) : rows(m), cols(n) {
    data = new double*[rows];
    cout << "allocated memory for Matrix: " << rows * cols * sizeof(double) << " bytes." << endl;
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = fill_value;//fill with value
        }
    }
}

Matrix::Matrix(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;

    data = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;//handle self-assignment
    }

    //free existing 
    if (data) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    //allocate new memory and copy data
    rows = other.rows;
    cols = other.cols;

    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }

    return *this;
}

Matrix::~Matrix() {
    if (data) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        cout << "freed memory for Matrix." << endl;
    }
    data = nullptr;
}

double Matrix::get(int i, int j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw out_of_range("index out of bounds");
    }
    return data[i][j];
}

void Matrix::set(int i, int j, double value) {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw out_of_range("index out of bounds");
    }
    data[i][j] = value;
}

int Matrix::get_height() const { return rows; }
int Matrix::get_width() const { return cols; }

void Matrix::negate() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = -data[i][j];
        }
    }
}

void Matrix::add_in_place(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw invalid_argument("Matrix dimensions must match for addition");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] += other.data[i][j];
        }
    }
}

Matrix Matrix::multiply(const Matrix& other) const {
    if (cols != other.rows) {
        throw invalid_argument("Matrix sizes do not match for multiplication");
    }
    Matrix result(rows, other.cols, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            for (int k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

//compound assignment operators
Matrix& Matrix::operator+=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw invalid_argument("Matrix sizes do not match for += operation");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw invalid_argument("Matrix sizes do not match for -= operation");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] -= other.data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(double scalar) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] *= scalar;
        }
    }
    return *this;
}

Matrix& Matrix::operator/=(double scalar) {
    if (scalar == 0) {
        throw invalid_argument("Division by zero");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] /= scalar;
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw invalid_argument("Matrix dimensions must match for addition");
    }
    Matrix result(rows, cols, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw invalid_argument("Matrix dimensions must match for subtraction");
    }
    Matrix result(rows, cols, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    return multiply(other);
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator/(double scalar) const {
    if (scalar == 0) {
        throw invalid_argument("Division by zero");
    }
    Matrix result(rows, cols, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] / scalar;
        }
    }
    return result;
}

void Matrix::print() const {
    bool isInteger = true;

    for (int i = 0; i < rows && isInteger; i++) {
        for (int j = 0; j < cols && isInteger; j++) {
            if (data[i][j] != static_cast<int>(data[i][j])) {
                isInteger = false;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isInteger) {
                cout << static_cast<int>(data[i][j]) << " ";
            } else {
                cout << fixed << setprecision(1) << data[i][j] << " ";
            }
        }
        cout << endl;
    }
}

//non-member operator function for scalar multiplication
Matrix operator*(double scalar, const Matrix& mat) {
    return mat * scalar;
}

//non-member operator function for unary negation
Matrix operator-(const Matrix& mat) {
    Matrix result = mat;
    result.negate(); 
    return result;
}

//move Constructor
Matrix::Matrix(Matrix&& other) noexcept  : rows(other.rows), cols(other.cols), data(other.data) {
    other.data = nullptr; 
    cout << "Moved memory for Matrix." << endl;
}

//move Assignment Operator
Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {  
        
        if (data) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
        }

        //takimg resources from the other matrix
        rows = other.rows;
        cols = other.cols;
        data = other.data;

        //setting the source matrix to empty
        other.data = nullptr;
        cout << "Moved memory for Matrix." << endl;
    }
    return *this;
}
