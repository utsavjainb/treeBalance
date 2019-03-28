//Utsav Jain
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue> 
#include <string>
using namespace std;
#define COUNT 10

template <class T> class Stack {
    public:
        int top;
        T a[1000];    
    
        Stack()  { 
            top = -1; 
        }

        bool push(T x) {
            if (top >= (999)) {
                cout << " Overflow";
                return false;
            }
            else {
                a[++top] = x;
                return true;
            }
        }

        T pop() {
            if (top < 0) {
                cout << " Underflow";
                return 0;
            }
            else {
                T x; 
                x = a[top--];
                return x;
            }   
        }

        T getTop() {
            return a[top];
        }

        bool isEmpty() {
            return (top < 0);
   
        }
};
 



template <class T> class TreeNode {
    public:
        T data;
        TreeNode<T>* left;
        TreeNode<T>* right;
};

template <class T> class BinaryTree {
       
    public:
        TreeNode<T>* root;
        BinaryTree(){
            this->root = NULL;

        }

        void insert(T val, TreeNode<T>* leaf){
            if(val < leaf->data) {
                if(leaf->left != NULL) {
                    insert(val, leaf->left);
                }
                else {
                    leaf->left = new TreeNode<T>();
                    leaf->left->data = val;
                    leaf->left->left = NULL;
                    leaf->left->right = NULL;
                }
            }
            
            else if(val >= leaf->data){
                if(leaf->right != NULL){
                    insert(val, leaf->right);
                }
                else {
                    leaf->right = new TreeNode<T>();
                    leaf->right->data = val; 
                    leaf->right->left = NULL;
                    leaf->right->right = NULL;
                }
            }
        }

        void insert(T val) {
            if(this->root != NULL){
                insert(val, this->root);
            }
            else {
                this->root = new TreeNode<T>();
                this->root->data = val;
                this->root->left = NULL;
                this->root->right = NULL;
            }
        }




        TreeNode<T>* search(T val, TreeNode<T>* leaf) {         

            if(leaf != NULL) {            
                if(leaf->data == val) {
                    return leaf;
                }

                else if(val >= leaf->data) {
                    return search(val, root->right);
                }

                else if (val < leaf->data){
                    return search(val, root->left);
                }                
            }

            else {
                return NULL;
            }

        }


        TreeNode<T>* search(T val) {
            return search(val,this->root);
        }

    void inOrder(TreeNode<T>* leaf) {
        if(leaf != NULL) {
            inOrder(leaf->left);
            cout << leaf->data << ", ";
            inOrder(leaf->right);
        }
    }

    void inOrder() {
        inOrder(this->root);
        cout << endl;
    }

    void postOrder() {
        postOrder(this->root);
        cout << endl;
    }

    void postOrder(TreeNode<T>* leaf) {
        if(leaf != NULL){
		    inOrder(leaf->left);
		    inOrder(leaf->right);
		    cout << leaf->data << ", ";
        }   
    }

    void preOrder() {
        preOrder(this->root);
        cout << endl;
    }


    void preOrder(TreeNode<T>* leaf) {
        if(leaf != NULL){
            cout << leaf->data << ", ";
            inOrder(leaf->left);
            inOrder(leaf->right);
        }
    }


    TreeNode<T>* ll_rotation(TreeNode<T>* parent) {
        TreeNode<T>* temp = parent->left;
        parent->left = temp->right;
        temp->right = parent;
        return temp;
    }

    TreeNode<T>* lr_rotation(TreeNode<T>* parent) {
        TreeNode<T>* temp = parent->left;
        parent->left = rr_rotation(temp);
        return ll_rotation(parent);
    }

    TreeNode<T>* rr_rotation(TreeNode<T>* parent) {
        TreeNode<T>* temp = parent->right;
        parent->right = temp->left;
        temp->left = parent;
        return temp;
    }

    TreeNode<T>* rl_rotation(TreeNode<T>* parent) {
        TreeNode<T>* temp = parent->right;
        parent->right = ll_rotation(temp);
        return ll_rotation(parent);
    }


    void transform (TreeNode<T>* node, int count ) {
        TreeNode<T>* treerover = node;

        for ( int j = 0; j < count; j++) {
            TreeNode<T>* sub = treerover->right;
            treerover->right = sub->right;
            treerover = treerover->right;
            sub->right = treerover->left;
            treerover->left = sub;
        }  
    }  
    


    void balance ( int length ) {
        TreeNode<T>* node = this->root; 
        int r = 1;
        while ( r <= length ) {     
            r = (2*r) + 1;
        }   
        int counter = r/2;
        transform(node, length - counter);
        for ( length = counter; length > 1; length /= 2) {
            transform( node, length/2 );
        }
    }


    void printer(TreeNode<T> *root, int space){
        if (root == NULL)
            return;
        space += COUNT;
    
        printer(root->right, space);

        cout << endl;
        for (int i = COUNT; i < space; i++) {
            cout << " ";
        }
        cout << root->data << endl;
    
        printer(root->left, space);
    }
    
    void printTree() {
        printer(this->root->right, 0);
    }
    
};





int main() {

    BinaryTree<int> t1;
    t1.insert(2);
    t1.insert(4);
    t1.insert(5);
    t1.insert(7);
    t1.insert(13);
    t1.insert(16);
    t1.insert(19);
    t1.insert(21);
    t1.insert(25);
    t1.insert(30);



    cout << "Original Degenerate Tree:" << endl;
    t1.printTree();

    t1.balance(9);
    cout << "Balancing..." << endl;
    t1.printTree();



    return 0;
}
