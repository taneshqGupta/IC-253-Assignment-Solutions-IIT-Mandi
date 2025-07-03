#include <bits/stdc++.h>
using namespace std;

class Tree{

    struct Node{
        int data;
        Node *left, *right, *parent;
        Node(int v) : data(v), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node *root;
    static const int MAX_NODES = 100;

    void preorder(Node* node){
        if(!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node){
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
    
    Tree(): root(nullptr) {}

    void insert(int val){
        Node* newNode = new Node(val);
        if(!root){
            root = newNode;
            return;
        }
        Node *nodes[MAX_NODES];
        int start = 0;
        int end = 0;
        nodes[end++] = root;
        while(start < end) {
            Node *curr = nodes[start++];
            if(!curr->left){
                curr->left = newNode;
                newNode->parent = curr;
                return;
            } else {
                nodes[end++] = curr->left;
            }
            if(!curr->right){
                curr->right = newNode;
                newNode->parent = curr;
                return;
            } else {
                nodes[end++] = curr->right;
            }            
        }
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

int main(){
    Tree mango;
    for(int i=0; i<18; i++) mango.insert(i+1);
    mango.preorder(); cout << '\n';
    mango.inorder(); cout << '\n';
    mango.postorder(); cout << '\n';
}