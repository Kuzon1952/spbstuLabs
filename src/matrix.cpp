#include "matrix.hpp"
#include <iostream>
#include <stdexcept>


using namespace std;

Matrix::Matrix(int n):rows(n),cols(n){//identity matrix
    data = new double*[rows];
    for(int i = 0; i< rows; i++){
        data[i]= new double[cols]{0};
        data[i][i]=1;
    }

}

Matrix::Matrix(int m, int n, double fill_value): rows(m), cols(n){//general matrix constructor m x n and all elements = fill_value
    data = new double*[rows];
    for(int i = 0; i<rows; i++){
        data[i]=new double[cols];
        for(int j=0; j<cols;j++){
            data[i][j]=fill_value;
        }
    }
}

Matrix::Matrix(const Matrix& other): rows(other.rows),cols(other.cols){//copy constructor
    data=new double*[rows];
    for(int i=0; i < rows;i++){
        data[i]=new double[cols];
        for(int j=0; j<cols; j++){
            data[i][j]=other.data[i][j];
        }
    }
}

Matrix::~Matrix(){
    if(data){
        for(int i=0; i<rows; i++){
            delete[] data[i];//delete each row
        }
    }
    delete[] data;
    data = nullptr;
}



double Matrix::get(int i, int j) const{//setting an element at position (i,j)
    if(i < 0 || i >= rows || j < 0 || j >= cols){
        throw out_of_range("index out of bounds");
    }
    return data[i][j];

}

void Matrix::set(int i, int j, double value){
    if(i<0 || i>= rows || j<0 || j>= cols){
        throw out_of_range("index out of bounds");
    }
    data [i][j] = value;
}

//get matrix dimensions
int Matrix::get_height() const {return rows;}
int Matrix::get_width() const {return cols;}

void Matrix::negate(){//negate matrix -A
    for(int i = 0; i< rows;i++){
        for(int j = 0; j<cols; j++){
            data[i][j]=-data[i][j];
        }
    }
}

void Matrix::add_in_place(const Matrix& other){//matrix multiplication A*B
    if(rows != other.rows || cols != other.cols){
        throw invalid_argument("matrix sizes do not match for addition");
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j< cols; j++){
            data[i][j]+=other.data[i][j];
        }
    }


}

Matrix Matrix::multiply(const Matrix& other) const{// A * B
    if(cols != other.rows){
        throw invalid_argument("matrix sizes do not match for multiplication");
        
    }
    Matrix  result(rows, other.cols, 0);
    for(int i = 0; i< rows;i++){
        for(int j=0; j< other.cols;j++){
            for(int k=0; k<cols;k++){
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

void Matrix::print() const{//print matrix
    for(int i = 0; i<rows; i++){
        for(int j=0; j<cols;j++){
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
}
void fibonacci(int n){
    
    Matrix m(2, 2);//2x2 
    m.set(0, 0, 1);
    m.set(0, 1, 1);
    m.set(1, 0, 1);
    m.set(1, 1, 0);

    
    Matrix v(2, 1);//2x1
    v.set(0, 0, 1); 
    v.set(1, 0, 0); 
    
    for (int i = 0; i < n - 1; i++){
        Matrix temp= m.multiply(v);  
        double a =temp.get(0, 0);  
        double b= temp.get(1, 0);  
        
        v.set(0, 0, a);
        v.set(1, 0, b);
    }
    cout<<v.get(0, 0)<<endl;
}