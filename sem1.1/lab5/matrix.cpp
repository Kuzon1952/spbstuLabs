#include "matrix.h"
#include <iostream>
#include <iomanip>//for fixed and setprecision

using namespace std;
//3.2.1
Matrix createMatrix(size_t rows, size_t cols) {
    Matrix matrix;
    matrix.rows = rows;//setting nums of rows 
    matrix.cols = cols;//setting nums of cols

    matrix.data = new double*[rows];//allocating memory for rows
    for (size_t i = 0; i<rows; ++i) {
        matrix.data[i] = new double[cols]{0};//allocating and initializing col to 0
    }
    return matrix; 
}

void deleteMatrix(Matrix& matrix) {//free memory
    for (size_t i = 0; i < matrix.rows; ++i) {
        delete[] matrix.data[i];//delete each row
    }
    delete[] matrix.data;//delete the array of row pointers
    matrix.data = nullptr;//set pointer to null to avoid dangling pointers
}

void setElement(Matrix& matrix, size_t row, size_t col, double value) {//seting a specific element
    if (row < matrix.rows && col < matrix.cols) {//checking bounds
        matrix.data[row][col] = value;//assign the value to the specific cell
    } else {
        cout<<"Index out of bounds."<<endl;//invalid indices
    }
}

double getElement(const Matrix& matrix, size_t row, size_t col) {//getting specific elements from the matrix
    if (row< matrix.rows && col < matrix.cols) {//checking bounds
        return matrix.data[row][col];//return the value of the specific cell
    } else {
        cout<<"Index out of bounds." <<endl;
        return 0.0;//return a default value
    }
}

void displayMatrix(const Matrix& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {//iterate over rows
        for (size_t j = 0; j < matrix.cols; ++j) {//iterate over cols
            cout << matrix.data[i][j] << " ";//print each element
        }
        cout<<endl;//newline after each row
    }
}

//3.2.2
void m_zero(Matrix* A, int m, int n) {//initializing 
    if (m <= 0 || n <= 0){
        cout<<"Matrix dimensions must be positive.";

    }     
    A->rows = m;
    A->cols = n;
    A->data = new double*[m];
    for (int i = 0; i < m; ++i) {
        A->data[i] = new double[n]{0};//initializing 0 each row
    }
}

void m_id(Matrix* A, int n) {//initializing an identity matrix
    if (n <= 0) throw invalid_argument("Matrix size must be positive.");
    m_zero(A, n, n);//initialize matrix with zeros
    for (int i = 0; i < n; ++i) {
        A->data[i][i] = 1.0; //setting diagonal elements to 1
    }
}

void m_free(Matrix* A){//freeing memory
    if (A->data) {
        for (int i = 0; i < A->rows; ++i) {
            delete[] A->data[i];//free each row
        }
        delete[] A->data;//free the row pointers
        A->data = nullptr;
    }
    A->rows = 0;
    A->cols = 0;
}

void m_copy(const Matrix* src, Matrix* dst){ //function to copy from one to another matrix 
    if (!src->data) 
    {
        cout<<("Source matrix is empty.");
    }
    m_zero(dst, src->rows, src->cols);//initialize destination matrix
    for (int i = 0; i < src->rows; ++i) {
        for (int j = 0; j < src->cols; ++j) {
            dst->data[i][j] = src->data[i][j];
        }
    }
}

int m_width(const Matrix* A) {//get width
    return A->cols;
}

int m_height(const Matrix* A) {//get height
    return A->rows;
}

double m_get(const Matrix* A, int i, int j){//function to get he value of the i,jth elemment of a matrix
    if (i < 0 || i >= A->rows || j < 0 || j >= A->cols) {
        cout<<("Index out of bounds.");
    }
    return A->data[i][j];
}


void m_set(Matrix* A, int i, int j, double value){//function to set the value of the i,j-th element of a matrix
    if (i < 0 || i >= A->rows || j < 0 || j >= A->cols) {
        cout<<("Index out of bounds.");
    }
    A->data[i][j] = value;
}

void displayMatrix1(const Matrix& A) {//printing 
    for (size_t i = 0; i < A.rows; ++i) {
        for (size_t j = 0; j < A.cols; ++j) {
            cout << A.data[i][j]<<" ";
        }
        cout<<endl;
    }
}

//3.2.3
int m_add(Matrix* A, const Matrix* B) {//adding function for adding two matrix
    if (A->rows != B->rows || A->cols != B->cols) {
        return 1;//matrices are not the same size
    }
    for (size_t i = 0; i < A->rows; ++i) {
        for (size_t j = 0; j < A->cols; ++j) {
            A->data[i][j] += B->data[i][j];
        }
    }
    return 0;
}

//negate
void m_neg(Matrix* A){
    for (size_t i = 0; i < A->rows; ++i) {
        for (size_t j = 0; j < A->cols; ++j) {
            A->data[i][j] = -A->data[i][j];
        }
    }
}

//multiply two matrices
int m_mult(const Matrix* A, const Matrix* B, Matrix* dst) {
    if (A->cols != B->rows) {
        return 1;//dimensions do not allow multiplication
    }
    m_zero(dst, A->rows, B->cols);//initialize the destination matrix using function
    for (size_t i = 0; i < A->rows; ++i) {
        for (size_t j = 0; j < B->cols; ++j) {
            for (size_t k = 0; k < A->cols; ++k) {
                dst->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }
    return 0;
}

//3.2.4
void fibonacci_matrix() {
    Matrix F;
    m_zero(&F, 2, 2);
    m_set(&F, 0, 0, 1);
    m_set(&F, 0, 1, 1);
    m_set(&F, 1, 0, 1);
    m_set(&F, 1, 1, 0);

    Matrix V, Vn;
    m_zero(&V, 2, 1);
    m_set(&V, 0, 0, 1);//F(1)
    m_set(&V, 1, 0, 0);//F(0)
    cout<<fixed<<setprecision(0);//forces the output to use fixed-point notation
    cout<<"First 40 Fibonacci numbers:"<<endl;
    cout<<"F[0]: 0"<<endl;
    for (int i = 1; i < 40; ++i) {
        if (i > 1) {
            m_mult(&F, &V, &Vn);//multiply transformation matrix with vector
            m_free(&V);//free old vector
            V = Vn;//update vector
        }
        cout<<"F["<<i<<"]: "<<m_get(&V, 0, 0)<<endl;
    }

    m_free(&F);
    m_free(&V);
}


