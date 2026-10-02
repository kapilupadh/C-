#include<iostream>
using namespace std;



class Node {
    public :
        int data;
        Node* left;
        Node* right;

        Node(int val ) : data(val ), left(nullptr), right (nullptr){}

};


class LinkedListBST {
    private :
        Node* root;
    public :
        LinkedListBST() : root(nullptr){}

        void insert(int key){


            Node* newNode = new Node(key);
            if(root ==nullptr){
                 
                root =newNode;
                return;
            }
            Node* current = root;
            Node* parent = nullptr;

            while(current != nullptr){
                if(current->data <key){
                    parent = current ;
                    current = current->right;

                }else if ( current->data > key ){
                    parent = current;
                    current = current->left;
                }else {
                    cout<<"Key exist ";
                    return;
                }


            }
            if(parent->data <key ){
                parent->right = newNode;

            }else {
                parent->left = newNode;
            }

        }  


        void inorder(Node * node){
            if(node == nullptr) return;

            inorder(node->left);
            cout<<node->data<<" ";
            inorder(node->right);
        }

        void Show (){

            Node *c = root;
            inorder(c);
            
        }


};
int main() {
    LinkedListBST BST ;
    BST.insert(20);
    BST.insert(50);
    BST.insert(70);
    BST.insert(40);

    BST.Show();
}