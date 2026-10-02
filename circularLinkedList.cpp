#include<iostream>
using namespace std;



class Node {
    private :
        int data ;
        Node* next ;

    public :
        Node (int val) : data(val), next(nullptr) {}

        int getData () const {return data;}
        void setData (int val)
        {
            data = val;
        } 
        Node* getNext (){
            return next;
        }
        void setNext (Node* ptr){
            next = ptr;
        }
};


class CircularLL {
    private :
        Node* head ;
        Node* tail ;


    public : 
        CircularLL (){
            head = nullptr;
            tail = nullptr;
        }
        ~CircularLL ();
        void push_front(int val);
        void push_back (int val);
        void deleteNodeFront();
        void deleteNodeBack();
        void printLL();

};


CircularLL :: ~CircularLL() {
    if(head == nullptr) return;

    Node* current = head->getNext();
    while(current != head){
        Node* nextNode = current->getNext();
        delete current ;
        current = nextNode;
    }
    delete head;
    head = tail = nullptr;

}


void CircularLL :: push_front(int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = tail = newNode ;
        tail->setNext(head);
        return ;
    }
    newNode->setNext(head); // new node points to head 
    head = newNode ; // head points to new node 
    tail->setNext(head); // tail points to head 
}

void CircularLL :: printLL() {
    if(head == nullptr){
        cout<<"list is empty \n";
        return ;
    }
    cout<<head->getData()<<"->";
    Node* temp = head->getNext();

    while(temp != head){
        cout<<temp->getData()<< "->";
        temp = temp->getNext();
    }
    cout<<temp->getData()<<"\n";
}


void CircularLL :: push_back(int val){
    Node* newNode = new Node(val );


    if(head == nullptr){
        head = tail = newNode ;
        tail->setNext(head);
        return ;
    }
    newNode->setNext(head);
    tail->setNext(newNode);
    tail = newNode;
}

void CircularLL :: deleteNodeFront(){
    if(head == nullptr){
        return;
    }
    if(head == tail){
        delete head;
        head = tail = nullptr;
        return;
    }
    Node* temp = head;
    head->getNext();
    tail->setNext(head); // not sure 
    temp->setNext(nullptr);
    delete temp;


}
void CircularLL :: deleteNodeBack() {
    if(head == nullptr){
        return;
    }
    if(head == tail ){
        delete head ;
        head = tail = nullptr;
        return ;
    }
    Node* temp = tail;
    Node* prev = head;

    while(prev->getNext() != tail){
        prev= prev->getNext();
    }
    tail = prev ;
    tail->setNext(head);
    temp->setNext(nullptr);
    delete temp;
}



int main () {
    CircularLL cll;

    cll.push_front(1);
    cll.push_front(2);
    cll.push_front(3);
    cll.push_front(4);


    cll.printLL();


    cll.push_back(10);
    cll.printLL();

    cll.deleteNodeFront();
    
}