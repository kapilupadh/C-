#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;

public:
    Node(int val) : data(val), next(nullptr) {}

    int getData() const {
        return data;
    }

    void setData(int val) {
        data = val;
    }

    Node* getNext() const {
        return next;
    }

    void setNext(Node* ptr) {
        next = ptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList();

    void push_front(int val);
    void push_back(int val);
    void pop_front();
    void pop_back();
    void printLL() const;
    void insert(int val, int pos);
    int search(int val) const;
};

LinkedList::~LinkedList() {
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->getNext();
        delete current;
        current = next;
    }

    head = tail = nullptr;
}

void LinkedList::push_front(int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    newNode->setNext(head);
    head = newNode;
}

void LinkedList::push_back(int val) {
    if (head == nullptr) {
        push_front(val);
        return;
    }

    Node* newNode = new Node(val);
    tail->setNext(newNode);
    tail = newNode;
}

void LinkedList::pop_front() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->getNext();

    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
}

void LinkedList::pop_back() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* temp = head;

    while (temp->getNext() != tail) {
        temp = temp->getNext();
    }

    cout << "Popped element: " << tail->getData() << endl;

    delete tail;
    tail = temp;
    tail->setNext(nullptr);
}

void LinkedList::insert(int val, int pos) {
    if (pos < 0) {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 0) {
        push_front(val);
        return;
    }

    Node* temp = head;

    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->getNext();
    }

    if (temp == nullptr) {
        cout << "Invalid position\n";
        return;
    }

    Node* newNode = new Node(val);

    newNode->setNext(temp->getNext());
    temp->setNext(newNode);

    if (temp == tail) {
        tail = newNode;
    }
}

int LinkedList::search(int val) const {
    Node* temp = head;
    int index = 0;

    while (temp != nullptr) {
        if (temp->getData() == val) {
            return index;
        }

        temp = temp->getNext();
        index++;
    }

    return -1;
}

void LinkedList::printLL() const {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->getData() << " -> ";
        temp = temp->getNext();
    }

    cout << "NULL" << endl;
}

int main() {
    LinkedList list;

    list.push_front(30);
    list.push_front(20);
    list.push_front(10);

    list.push_back(40);
    list.push_back(50);
    list.push_back(60);

    list.printLL();

    return 0;
}