class Matrix {
    private:
        int rows, cols;
        double** data; 
    
    public:
        Matrix(int n);//identity matrix(nxn)
        Matrix(int m, int n, double fill_value = 0);
        Matrix(const Matrix& other);//copy constructor

        Matrix(Matrix&& other) noexcept;//move constructor
        Matrix& operator=(const Matrix& other);//copy assignment operator
        Matrix& operator=(Matrix&& other) noexcept;//move assignment operator
    
        ~Matrix(); 

        //getter dimension
        double get(int i, int j) const;
        void set(int i, int j, double value);
    
        //get dimensions
        int get_height() const;
        int get_width() const;
    
        //matrix operations
        void negate();//-A
        void add_in_place(const Matrix& other);//A += B
        Matrix multiply(const Matrix& other) const;//A * B

        //compound assignment
        Matrix& operator+=(const Matrix& other);
        Matrix& operator-=(const Matrix& other);
        Matrix& operator*=(double scalar);
        Matrix& operator/=(double scalar);

        //binary operators
        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        Matrix operator*(double scalar) const;
        Matrix operator/(double scalar) const;
        
        void print() const;
};

//non-member operator functions
Matrix operator*(double scalar, const Matrix& mat);
Matrix operator-(const Matrix& mat);
