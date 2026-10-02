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

            // Push right child first so that left child is processed first
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
            // Reach the leftmost node of the current subtree
            while (current != nullptr) {
                st.push(current);
                current = current->leftChild;
            }

            // Current is nullptr here, pop item from stack
            current = st.top();
            st.pop();

            cout << current->data << " ";

            // Visit the right subtree
            current = current->rightChild;
        }
        cout << endl;
    }

    // Non-recursive Postorder Traversal (Left -> Right -> Root) using 2 Stacks
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

        // Print all elements from the second stack
        while (!st2.empty()) {
            cout << st2.top()->data << " ";
            st2.pop();
        }
        cout << endl;
    }
};

int main() {
    LinkedListBST BST;

    /*
         Constructing sample tree:
                   1
                 /   \
                2     3
               / \
              4   5
    */
    BST.root = new Node(1);
    BST.root->leftChild = new Node(2);
    BST.root->rightChild = new Node(3);
    BST.root->leftChild->leftChild = new Node(4);
    BST.root->leftChild->rightChild = new Node(5);

    cout << "Preorder Traversal:  ";
    BST.preorder();

    cout << "Inorder Traversal:   ";
    BST.inorder();

    cout << "Postorder Traversal: ";
    BST.postorder();

    return 0;
}