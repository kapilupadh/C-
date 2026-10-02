#include<iostream>
using namespace std ;

 class Node{
        private :
            int data ;
            Node * next ;
        public :
            Node(int val ) : data(val), next(nullptr) {
            } 
            int getData () const {
                return data;
            }
            void setData (int val) {
                data = val;
            }
            Node* getNext () const {
                return next ;
            }
            void setNext (Node* ptr){
                next = ptr;
            } 
    };
class SinglyLinkedlist {
    private :
        Node* head;
    public :
        SinglyLinkedlist () ;
        ~SinglyLinkedlist ();
            
        void InsertAtBeginning (int val);
        void InsertAtEnd (int val);
        bool find(int val) const ;
        void traverse () const ;
};

SinglyLinkedlist:: SinglyLinkedlist () : head(nullptr) {}

// Logic to insert at the Beginneing of the Stack
void SinglyLinkedlist :: InsertAtBeginning (int val) {

    Node* temp = new Node(val);

    if(head == nullptr) {
        head = temp;
    }
    else {
        temp -> setNext(head);
        head = temp ;
    }

};
// Logic to traverse of the Stack
void SinglyLinkedlist :: traverse () const {
    Node* current = head ;

    if(current == nullptr){
        cout<< "List is Empty";
        return ;
    }
    while(current != nullptr) {
        cout<< "Current data : "<< current->getData()<< endl;
        current = current->getNext() ;
        
    }
};

void SinglyLinkedlist :: InsertAtEnd (int val ) {
    Node* temp = new Node(val);
    Node* current = head;

    if(head == nullptr){
        head = temp ;
        return;
    }
   while ( current->getNext() != nullptr){
        current = current->getNext() ;
   }
   current->setNext(temp);
};

bool SinglyLinkedlist :: find(int val ) const {
    Node* current = head;

    while(current != nullptr){
        if(current->getData() == val){
            return true;
        }else {
            current = current->getNext(); 
        }  
    }
    return false ;  
};

 SinglyLinkedlist ::~SinglyLinkedlist () {

    while( head != nullptr){
        Node* temp = head;
        head = head->getNext() ;
        delete temp; 
    }
    cout<< "List is Empty now ."<< endl;
 }

int main () {
    SinglyLinkedlist list ;


    list.InsertAtBeginning(20);
    list.InsertAtBeginning(5);
    list.InsertAtBeginning(50);
    list.InsertAtBeginning(90);
   
    list.InsertAtEnd(23);

    list.traverse();

    if(list.find(20)){
        cout<<"20 Found ."<<endl;
    }else {
        cout << "20 is not Fould ."<< endl;
    }

    if(list.find(99)){
        cout<<"99 is Found"<< endl;
    }else {
        cout<<"99 is Not found "<< endl;
    }

    return 0 ;
}




