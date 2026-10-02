#include<iostream>
using namespace std;

class Shape {
    public :
        virtual double Area () {
            return 0;
        } 
        virtual ~Shape () {} 

};


class Circle : public Shape {
    double radius  ;
    public : 
        Circle (double r) : radius (r) {}

        double Area () override {
            return 3.14 * radius  * radius ; 
        }
};


class Square : public Shape {
    double side ;

    public : 
        Square(double s) : side (s) {} 

        double Area () override {
            return side * side ;
        }
};



int main () {
    Shape* circle = new Circle(2);
    Shape* square = new Square(4);
    
    cout<< "Circle Area : "<< circle->Area()<<endl;
    cout <<"Square Area : "<< square->Area() <<endl;

    
    return 0;

}