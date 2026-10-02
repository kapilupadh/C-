#include<iostream>
using namespace std;

class BankAccount {

    protected :
        // parent variable 
        double balance ;
    public :
        //Constructor    
        BankAccount (double initial_balance) : balance(initial_balance){}

        //pure virtual function
        virtual void withdraw (double amount ) = 0 ;

        // virtual destructor 

        virtual ~BankAccount () {} 
};


class SavingAccount : public BankAccount {
    public :
        // constructor which is sending the already leftover money 
        SavingAccount ( double initial ) : BankAccount(initial) {} 

        void withdraw (double amount ) override {

            if(amount > 500) {
                cout<< "Error : Cannot withdraw money more then 500$"<<endl;
            }
            else{
                balance -= amount ;
                cout << "Saving withdraw sucessful of amount :"<<amount << endl;
                cout << "Saving New Balance is  :"<<balance << endl;
            }
        }

};


class CurrentAccount : public BankAccount {
    public : 
        CurrentAccount (double initial ) : BankAccount(initial) {} 

        void withdraw (double amount ) override {
            
            if(amount > 0 && amount <= balance) {
                balance -= amount ;
                cout << "Current withdraw successful of amount : "<<amount << endl;
                cout << "Current New Balance is : "<<balance << endl;
            } 
            // ADDED: So it prints an error when it fails, instead of being silent
            else {
                cout << "Error: Not enough balance in Current Account to withdraw " << amount << "$" << endl;
            }
        }
};



int main () {
    BankAccount* myAccounts [] = {
        new SavingAccount(5000),
        new CurrentAccount(2500)
    };
        myAccounts[0]->withdraw(7500);
        myAccounts[0]->withdraw(500);
        myAccounts[0]->withdraw(900);

        myAccounts[1]->withdraw(7500);
        myAccounts[1]->withdraw(500);
        myAccounts[1]->withdraw(900);
    for (BankAccount* acc : myAccounts){
        delete acc;
    }
    
    return 0;


};