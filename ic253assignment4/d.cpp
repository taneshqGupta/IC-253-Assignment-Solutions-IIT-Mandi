#include <bits/stdc++.h>
using namespace std;

class BST{

    struct Node{
        int data;
        Node *right, *left, *parent;
        Node(int val): data(val), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node *root;
    static const int MAX_NODES = 100;

    void preorder(Node *node){
        if(!node) return;
        cout << node->data << ' ';
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node *node){
        if(!node) return;
        inorder(node->left);
        cout << node->data << ' ';
        inorder(node->right);
    }

    void postorder(Node *node){
        if(!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << ' ';
    }

    public:

    BST(): root(nullptr) {}

    int insert(int val){
        int comparisons = 0;
        Node *newNode = new Node(val);
        comparisons++; //whether root exists or not
        if(!root){
            root = newNode;
            return comparisons;
        }
        Node *curr = root;
        Node* parent = nullptr;
        while(curr){
            parent = curr;
            comparisons++; //val compared with curr's key
            if(val < curr->data) curr = curr->left;
            else curr = curr->right;
        }
        newNode->parent = parent;
        comparisons++; //val compared with parent's key
        if(val < parent->data) parent->left = newNode;
        else parent->right = newNode;
        return comparisons;
    }

    void preorder(){
        preorder(root);
        cout << '\n';
    }

    void inorder(){
        inorder(root);
        cout << '\n';
    }

    void postorder(){
        postorder(root);
        cout << '\n';
    }

};

int main() {

    BST mango;
    
    mango.insert(10);
    mango.insert(6);
    mango.insert(3);
    mango.insert(5);
    mango.insert(4);
    mango.insert(1);
    mango.insert(9);
    mango.insert(2);
    mango.insert(8);
    mango.insert(7);
    mango.insert(12);
    mango.insert(11);


    mango.preorder();
    cout << '\n';
    mango.inorder();
    cout << '\n';
    mango.postorder();
    cout << '\n';

}