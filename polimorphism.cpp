// // Compile time Polymorphism (Static ) 

// #include<iostream>
// #include<string>
// using namespace std;



// class Printer {
//     public : 

//         void show (int num) {

//             cout<<"Int num :" << num << endl;
//         }

//         void show (double num ){
//             cout << "Double num :" << num << endl;
//         }

//         void show (string num){
//             cout<<"String num :" << num << endl;
//         }

// };


// int main () {
//     Printer p ;


//     p.show (53) ;
    
//     p.show (3.2423) ;
    
//     p.show("Eight");

//     return 0;
// }




// Run time  Polymorphism (Dynamic)
#include<iostream>
using namespace std;



class Shape {
    public : 
        virtual double Area () = 0 ; 

        virtual ~Shape () {} 
};


class Circle : public Shape  {
    private : 
        double r ;
    public :
        Circle (double radius ) : r(radius) {}

        double Area () override {
            return 3.14 * r * r ;
        }
};



int main () {
    Shape * ptr = new Circle(4);

    cout << ptr->Area() <<endl;
    return 0;
}