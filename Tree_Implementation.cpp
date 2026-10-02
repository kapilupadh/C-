#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* leftChild;
    Node* rightChild;

    Node(int val) : data(val), leftChild(nullptr), rightChild(nullptr) {}
};

class LinkedListBST {
public:
    Node* root;

    LinkedListBST() : root(nullptr) {}

    // Destructor to clean up allocated memory non-recursively
    ~LinkedListBST() {
        if (root == nullptr) return;
        
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* current = st.top();
            st.pop();

            if (current->leftChild) st.push(current->leftChild);
            if (current->rightChild) st.push(current->rightChild);

            delete current;
        }
    }

    // Iterative Insert operation
    void Insert(int key) {
        if (root == nullptr) {
            root = new Node(key);
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (key < current->data) {
                current = current->leftChild;
            } else if (key > current->data) {
                current = current->rightChild;
            } else {
                cout << "Key " << key << " already exists!\n";
                return;
            }
        }

        // Allocate node only when insertion position is found
        if (key < parent->data) {
            parent->leftChild = new Node(key);
        } else {
            parent->rightChild = new Node(key);
        }
    }

    // Non-recursive Preorder Traversal (Root -> Left -> Right)
    void preorder() {
        if (root == nullptr) {
            cout << "Tree is Empty\n";
            return;
        }

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* current = st.top();
            st.pop();

            cout << current->data << " ";

            if (current->rightChild != nullptr) {
                st.push(current->rightChild);
            }
            if (current->leftChild != nullptr) {
                st.push(current->leftChild);
            }
        }
        cout << endl;
    }

    // Non-recursive Inorder Traversal (Left -> Root -> Right)
    void inorder() {
        if (root == nullptr) {
            cout << "Tree is Empty\n";
            return;
        }

        stack<Node*> st;
        Node* current = root;

        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->leftChild;
            }

            current = st.top();
            st.pop();

            cout << current->data << " ";

            current = current->rightChild;
        }
        cout << endl;
    }

    // Non-recursive Postorder Traversal (Left -> Right -> Root)
    void postorder() {
        if (root == nullptr) {
            cout << "Tree is Empty\n";
            return;
        }

        stack<Node*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            Node* current = st1.top();
            st1.pop();
            st2.push(current);

            if (current->leftChild != nullptr) {
                st1.push(current->leftChild);
            }
            if (current->rightChild != nullptr) {
                st1.push(current->rightChild);
            }
        }

        while (!st2.empty()) {
            cout << st2.top()->data << " ";
            st2.pop();
        }
        cout << endl;
    }
};

int main() {
    LinkedListBST BST;

    BST.Insert(50);
    BST.Insert(70);
    BST.Insert(30);
    BST.Insert(20);
    BST.Insert(40);

    cout<< "Preorder Traversal:  ";
    BST.preorder();

    cout << "Inorder Traversal:   ";
    BST.inorder();

    cout << "Postorder Traversal: ";
    BST.postorder();

    return 0;
}