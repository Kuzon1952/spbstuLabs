#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix{
    private:
    int rows, cols;
    double** data;//ptr for dynamic memory allocation

    public:
    Matrix(int n);//identity matrix (nxn)
    Matrix(int m, int n, double fill_value = 0);//general matrix will a fill val
    Matrix(const Matrix& other);//copy constructor

    ~Matrix();//destructor default

    //getter dimensions
    double get(int i, int j) const;
    void set(int i, int j, double value);

    //get dimensions
    int get_height() const;
    int get_width() const;

    //matrix operations
    void negate();//-A
    void add_in_place(const Matrix& other);//A+=B
    Matrix multiply(const Matrix& other) const;//A*B

    //display matrix
    void print() const;
   

};
void fibonacci(int n);
#endif //MATRIX_HPP
