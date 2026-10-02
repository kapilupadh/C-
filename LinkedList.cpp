#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *Head;
    Node *Tail;

public:
    LinkedList()
    {
        Head = Tail = NULL;
    }

    void push_front(int val)
    {
        Node* newNode = new Node(val); // dynamic

        if (Head == NULL)
        {
            Head = Tail = newNode;
            return;
        }
        else
        {
            newNode->next = Head;
            Head = newNode;
        }
    }

    void printLL()
    {
        Node *temp = Head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val); // dymanically created node

        if (Head == NULL)
        {
            Head = Tail = newNode;
            return;
        }
        else
        {
            Tail->next = newNode;
            Tail = newNode;
        }
    }

    void pop_front()
    {

        if (Head == NULL)
        {
            cout << "Cannot perform Pop operation (List empty) :" << endl;
            return;
        }
        else
        {
            Node* temp = Head; // head address -> temp 
            Head = Head->next; // head address -> next element 
            temp->next = NULL; // temp releases the memory 

            cout << "Poped element : " << temp->data << endl;

            delete temp;
        }
    }

    void pop_back () {
        Node* temp = Head;

            if(Head == NULL ){
                return ;
            }
            while (temp->next != Tail){
                temp = temp -> next;
            }
            temp->next = NULL;
            cout << "Poped element : " << Tail->data << endl;
            delete Tail;
            Tail = temp ;
             
    }

    void insert(int val , int pos ){
        if(pos < 0 ){
            cout<<"Invalid pos \n";
            return;
        }
        if ( pos == 0){
            push_front(val);
            return ;
        }

        Node* temp = Head;
        for(int i = 0 ; i< pos-1; i++){
            if(temp == NULL){
                cout<<"Invalid pos \n";
                return ;
            }
            temp = temp->next;
        }
        Node* newNode =new  Node(val);
        newNode-> next = temp->next ;
        temp->next = newNode;
        

    }

    int search (int key){
        Node* temp = Head;
        int idx = 0;

        while(temp != NULL){
            if(temp->data == key ){
                return idx;
            }

            temp = temp->next ;
            idx++;
        }
        return -1;
    }
};

int main()
{
    LinkedList ll;

    ll.push_back(0);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.printLL();


    ll.insert(6,6);

    ll.printLL();
    ll.insert(5,4);
    ll.printLL();
    return 0;
}