#include<iostream>
using namespace std;


class BankAccount {
    private :
        double balance ;

        double IsValidTransection(double amount){

           return amount > 0;
        }
    public : 
        BankAccount (double b) : balance(b) {} //constructor initializing the class

        void deposit (double amount ) {
            if(IsValidTransection(amount)){
                balance += amount ;
                cout<< "Amount Added sucessfully of :"<<amount <<endl;
                cout<< "Total balance in account :"<<balance <<endl;
            }
        }
        void withdrawn (double amount ){
            if(IsValidTransection(amount ) && amount >=0 ){
                balance -= amount;
                cout << "Amount withdrawn sucessfully :"<< amount<<endl;
                cout << "Total balance in account  :"<< balance <<endl;
            }
            else {
                cout << "something went wrong || Error."<<endl;
            }
        }
        double getBalance () const {
            return balance ;
        }
};

int main () {
    BankAccount acc(10000);
    acc.getBalance(); 
    
    acc.withdrawn(721.65);

    acc.getBalance();

    return 0;
}