#include<iostream>
using namespace std;


class BankAccount {
    private :
        double Balance ;
    public :
        BankAccount (double b) : Balance (b) {}

        void deposite (double amount) {

            if(amount > 0) {
                Balance += amount ;
            }
        }
        void withdraw (double amount ) {
            if(amount > Balance ){
                cout<< "Low Balance, is : "<< Balance<<endl;
                cout<< "Amount tring to withdraw :"<<amount <<endl;
            }
            else  {
                Balance -= amount ;
                cout<< "Remaining Balance is : "<< Balance<<endl;
            }
        }
        double getBalance () const {
            return Balance;
        }
};



int main(){
    BankAccount acc(500);

    acc.deposite(500);

    acc.withdraw(150);


    return 0;
}