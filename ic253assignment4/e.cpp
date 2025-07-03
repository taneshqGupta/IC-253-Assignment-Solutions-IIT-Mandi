#include <bits/stdc++.h>
using namespace std;

class AVL{

    struct Node{
        int key, height;
        Node *left, *right, *parent;
        Node(int val): key(val), left(nullptr), right(nullptr), parent(nullptr), height(1) {}
    };

    Node *root;

    int height(Node *node){
        return (node ? node->height : 0);
    }

    int balance_factor(Node *node){
        return height(node->left) - height(node->right);
        // more than +1 ==> too heavy on left;
        // less than -1 ==> too heavy on right;
    }

    void updateHeight(Node *node){
        node->height = 1 + max(height(node->left), height(node->right));
    }

    Node* rotate_right(Node *p){
        Node *q = p->left;
        p->left = q->right;
        if(q->right) q->right->parent = p;
        q->right = p;
        q->parent = p->parent;
        p->parent = q;
        if (q->parent) {
            if (q->parent->left == p) q->parent->left = q;
            else if (q->parent->right == p) q->parent->right = q;
        }
        updateHeight(p);
        updateHeight(q);
        return q;
    }

    Node* rotate_left(Node *p){
        Node *q = p->right;
        p->right = q->left;
        if(q->left) q->left->parent = p;
        q->left = p;
        q->parent = p->parent;
        p->parent = q;
        if (q->parent) {
            if (q->parent->left == p) q->parent->left = q;
            else if (q->parent->right == p) q->parent->right = q;
        }
        updateHeight(p);
        updateHeight(q);
        return q;
    }

    Node *rotate_left_right(Node *p){
        p->left = rotate_left(p->left);
        return rotate_right(p);
    }

    Node *rotate_right_left(Node *p){
        p->right = rotate_right(p->right);
        return rotate_left(p);
    }

    Node *rebalance(Node *p){
        if(!p) return p;
        int bf = balance_factor(p);
        if(bf > 1){  //too heavy on the left
            if(balance_factor(p->left) >= 0){
                p = rotate_right(p); //single rotation if left-left is heavy or balanced.
            }
            else{
                p = rotate_left_right(p); //double rotation if left-right is heavy.
            }
        } else if (bf < -1){ //too heavy on the right
            if(balance_factor(p->right) <= 0){
                p = rotate_left(p); //single rotation if right-right is heavy or balanced.
            }
            else{
                p = rotate_right_left(p); //double rotation if right-left is heavy.
            }
        }
        updateHeight(p);
        return p;
    }

    Node *insert(Node* p, int key, Node* parent = nullptr){
        if(!p){
            Node *newNode = new Node(key);
            newNode ->parent = parent;
            return newNode;
        }
        if(key < p->key){
            p->left = insert(p->left, key, p);
        } else if (key > p->key){
            p->right = insert(p->right, key, p);
        } else {
            return p;
        }
        return rebalance(p);
    }

    Node *findMin(Node *p){
        while(p && p->left) p = p->left;
        return p;
    }

    Node *remove(Node *p, int key){
        if(!p) return nullptr;
        if(key < p->key) p->left = remove(p->left, key); else
        if(key > p->key) p->right = remove(p->right, key);
        else{
            if(!p->left || !p->right){
                Node *child = p->left ? p->left : p->right;
                if(child) child->parent = p->parent;
                delete p;
                return child;
            }
            else{
                Node *succ = findMin(p->right);
                p->key = succ->key;
                p->right = remove(p->right, succ->key);
            }
        }
        if(p) {
            updateHeight(p);
            return rebalance(p);
        }
        return nullptr;
    }

    void inorder(Node *node){
        if(!node) return;
        inorder(node->left);
        cout << node->key << ' ';
        inorder(node->right);
    }

    void preorder(Node *node){
        if(!node) return;
        cout << node->key << ' ';
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node *node){
        if(!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->key << ' ';
    }

    void printRotated(Node* node, int space = 0, int indent = 5) {
        if (!node) return;
        space += indent;
        printRotated(node->right, space);
        cout << setw(space) << node->key << "\n";
        printRotated(node->left, space);
    }

public:

    AVL(): root(nullptr) {}

    void insert(int key){
        root = insert(root, key);
        cout << "After insertion of " << key << ": \n";
        display();
    }

    bool search(int key){
        Node *p = root;
        bool ys = false;
        while(p){
            if(key == p->key){ ys = true; break; }
            if(key < p->key) p = p->left;
            if(key > p->key) p = p->right;
        }
        if(ys) cout << "key " << key << " found in tree.\n";
        else cout << "key " << key << " not found in tree\n";
        display();
        return ys;
    }

    void remove(int key){
        root = remove(root, key);
        cout << "After deletion of " << key << ": \n";
        display();
    }

    void display(){
        cout << "preorder: "; preorder(root); cout << '\n';
        cout << "inorder: "; inorder(root); cout << '\n';
        cout << "postorder: "; postorder(root); cout << '\n';
        cout << "structure:\n"; printRotated(root); cout << '\n';
    }

    void print(){
        inorder(root);
        cout << '\n';
    }
};

int main(){
    AVL tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(25);
    tree.insert(5);
    tree.insert(15);
    tree.remove(10);
    tree.remove(30);
    tree.search(25);
    tree.search(100);
}
