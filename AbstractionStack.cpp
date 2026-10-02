#include<iostream>
using namespace std ;



class Stack {
    public :
        virtual void Push(int x) = 0 ;
        virtual int Pop() = 0 ;
        virtual bool isEmpty () = 0 ;
        virtual ~Stack () {} 
};

class ArrayStack : public Stack {
    private :
        int arr[100] ;
        int topIndex = -1;
    public :
        void Push(int x) override {
            if(topIndex >= 99){
                cout<<"Stack is Full\n";
                return ;
            }
            arr[++topIndex] = x ;
        } 

        int Pop() override {
            if(isEmpty()){
                cout<<"Stack is UnderFlow ";
                return -1;
            }
            return arr[topIndex--];
        }


        bool isEmpty () override {
            return topIndex = -1 ;
        }
        
};



int main () {
    Stack* s = new ArrayStack () ;

    s->Push(21);
    s->Push(50);
    s->Push(31);

    cout<<"Poped ,"<< s->Pop() <<"\n";
    cout<<"Poped ,"<< s->Pop() <<"\n";
    cout<<"Poped ,"<< s->Pop() <<"\n";


    if(s->isEmpty()){
        cout<<"Stack is Empty\n "<<endl;
    }else {
        cout<<"stack is not emty\n "<<endl;
    }

    return 0;
    
}