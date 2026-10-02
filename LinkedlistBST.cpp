#include<iostream>
using namespace std;

class Node {
    public :
        int data;
        Node* left;
        Node* right;

        Node(int val) : data(val), left(nullptr), right(nullptr){}
};

class LinkedListBST {
    private :
        Node* root;
    public :
        LinkedListBST() : root(nullptr){};

    //1. Insertion 
    void Insert (int key ){

        Node* newNode = new Node(key) ;
        // For empty Tree
        if(root == nullptr){
            root = newNode;
            return;
        }
        Node* current = root;
        Node* parent = nullptr;
        // for non-empty tree

        while(current != nullptr){
            parent = current;

            if(key < current->data){
                current = current->left;
            }
            else if(key > current->data)
            {
                current = current->right;
            }
            else // node already exist 
            {
                delete newNode;
                return;
            }
        }

        if(key < parent->data){
            parent->left = newNode;
        }else{
            parent->right = newNode ;
        }
    }
    //2. Searching
    bool Search( int key){
        Node* current = root;

        while(current != NULL){
            if(current->data == key ){
                return true;
            }
            if(current->data > key){
                current = current-> left;
            }else {
                current = current->right;
            }

        }
        return false;
    }
    // 3. Find Minimum 

    int findMin(){
        if(root == nullptr){
            cout<<"Tree is empty";
            return -1;
        }
        Node* current = root;
        while ( current->left != nullptr){
            current = current->left;
        }
        return current->data;
    }

    // 4. find Maximun

    int findMax () {
        if(root == nullptr){
            cout<<"Tree is empty";
            return -1;
        }
        Node* current = root;

        while ( current->right != nullptr){
            current = current->right;
        }
        return current->data;
    }

    //5. Delete a Node 
    void DeleteNode(int key){
        Node* current = root;
        Node* parent = nullptr ;

        // traverse the tree ( finding the node )
        while( current != NULL && current->data != key ){
            parent = current ;
            if(key < current->data){
                current = current->left;
            }
            else 
            {
                current = current->right;
            }
        }

        if(current == NULL){
            return ;
            // Value doesnt exist in the tree
        }

        //case 1 : No leaf (left right no children )
        if(current->left == NULL && current->right == NULL){
            if(current !=root){
                if(parent->left == current){
                    parent->left = NULL;
                }else {
                    parent->right = NULL;
                }
            }
            else {
                root = NULL;
            }
            delete current ;
        }
        //2 : If only right node exist 
        else if (current->left == NULL){
            if(current != root){
                if(parent->left == current){
                    parent->left = current->right ;
                }else {
                    parent->right = current->right ;
                }

            }
            else {
                root = current->right ;
            }
            delete current;
        }
        //3. if only left node exist 
        else if ( current->right == NULL){
            if(current != root){
                if(parent->right == current ){
                    parent->right = current->left;
                }
                else {
                    parent->left = current->left;
                }
            }
            else {
                root = current->left ;
            }
            delete current;
        }
        // 4. node with 2 childs 
        else {
            Node* succParent = current;
            Node* succ = current->right ;

            while(succ->left != NULL){
                succParent = succ;
                succ= succ->left;
            }
            current->data = succ->data ;
            
            if(succParent->left == succ ){
                succParent->left = succ->right;

            }else {
                succParent->right = succ->right;
            }
            delete succ;

        }
    }

};

int main () {
    LinkedListBST tree;

    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(70);
    tree.Insert(60);
    tree.Insert(80);


    // cout<<"Inorder traversal after insert :";


    //search 
    cout<<"search 40: " << (tree.Search(40) ? "Found" : "Not Found") <<endl;
    cout<<"search 90: " << (tree.Search(90) ? "Found" : "Not Found") <<endl;


    //Min & Max 
    cout<<"Min : "<< tree.findMin() <<endl;
    cout<<"Max : "<< tree.findMax() <<endl;

    //Delete a Leaf
    tree.DeleteNode(20);
    

    return 0;
}