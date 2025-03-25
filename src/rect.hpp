
//refactorized
#ifndef RECT_HPP
#define RECT_HPP

class Rect{
    private:
    //old valriables:
    //int left, right, top, bottom;

    //new variables:
    int x;//int left;//left X'-axis which is x_min
    int y;//int right;//right X-axis which is x_max
    int width;//int top;//top Y-axis which is y_max
    int height;//int bottom;//bottom Y'-axis which is y_min

    public:
    Rect();//default constructor
    Rect (int l, int r, int t, int b);//constructor with parameters
    Rect(const Rect& other);//copy constructor
    ~Rect();//destructor

    //getter methods
    int getLeft() const;
    int getRight() const;
    int getTop() const;
    int getBottom() const;

    //getter methods
    int get_left() const;
    int get_right() const; 
    int get_top() const;
    int get_bottom() const;

    //setter methods
    void setLeft(int l);
    void setRight(int r);
    void setTop(int t);
    void setBottom(int b);

    void set_all(int l, int r, int t, int b);//setter for all 

    void move(int dx, int dy);

    //getter methods for properties
    int get_width() const;
    int get_height() const;
    int get_square() const;

    //setter methods for width and height (bottom - left corner)
    void set_width(int new_width);
    void set_heigth(int new_height);

    //overload methods
    void inflate(int amount);
    void inflate(int dw, int dh);
    void inflate(int d_left, int d_right, int d_top, int d_bottom);



    
};
 //function prototypes
 Rect bounding_rect(Rect r1, Rect r2);//it will return the smallest rectangle containg r1 and r2
 void print_rect(const Rect &r);//prints a rectangle

#endif // RECT_HPP
