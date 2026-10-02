#include<iostream>
using namespace std;


class Animal {
    protected :
        string name;
    public :
        Animal (string n) : name(n) {}
    
    void eat () {

        cout<< name<< "is eating"<<endl;
    }
    
};

class Dog : public Animal {
    public :
    Dog (string name) : Animal (name) {}

    void bark () {

        cout<<name << "is barking "<<endl;
    }
};


int main () {
    Dog d("Tommy");

    d.eat();
    d.bark();

    return 0;
    
}