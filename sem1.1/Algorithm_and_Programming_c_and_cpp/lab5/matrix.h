#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>//for size_t

struct Matrix
{
    size_t rows;//nums of rows
    size_t cols;//nums of cols
    double** data;//ptr to 2d arr
};

Matrix createMatrix(size_t rows, size_t cols);
void deleteMatrix(Matrix& matrix);
void setElement(Matrix& matrix, size_t row, size_t col, double value);
double getElement(const Matrix& matrix, size_t row, size_t col);
void displayMatrix(const Matrix& matrix);

void m_zero(Matrix* A, int m, int n);
void m_id(Matrix* A, int n);
void m_free(Matrix* A);
void m_copy(const Matrix* src, Matrix* dst);
int m_width(const Matrix* A);
int m_height(const Matrix* A);
double m_get(const Matrix* A, int i, int j);
void m_set(Matrix* A, int i, int j, double value);
void displayMatrix1(const Matrix& A);

int m_add(Matrix* A, const Matrix* B);
void m_neg(Matrix* A);
int m_mult(const Matrix* A, const Matrix* B, Matrix* dst);

void fibonacci_matrix();

#endif


