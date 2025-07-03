#include <bits/stdc++.h>
using namespace std;

class priorityQueue {
    struct Node{
        int p, val;
        Node *left, *right, *parent;
        Node(int p, int v): p(p), val(v), left(nullptr), right(nullptr), parent(nullptr) {}
    };
    Node *root;
    
    void inorder(Node *node){
        if(!node) return;
        inorder(node->left);
        cout << "--(" << node->p << ", " << node->val << ")--";
        inorder(node->right);
    }

    public:
        priorityQueue(): root(nullptr) {}

        void enqueue(int p, int v){
            Node *newNode = new Node(p, v);
            if(!root){
                root = newNode;
                return;
            }
            Node *curr = root;
            Node *parent = root->parent;
            while(curr){
                parent = curr;
                if(p < curr->p){
                    curr = curr->left;
                }
                else{
                    curr = curr->right;
                }
            }
            newNode->parent = parent;
            if(p < parent->p) parent->left = newNode;
            else parent->right = newNode;
        }

        void dequeue(){
            if(!root) return;
            Node *curr = root;
            while (curr->left) curr = curr->left;
            Node* target = curr;
            if(!target->right){
                if(!target->parent) root = nullptr;
                else if(target->parent->left == target) target->parent->left = nullptr;
                else target->parent->right = nullptr;
                delete target;
            }
            else {
                if(!target->parent){
                    root = target->right;
                    root->parent = nullptr;
                }
                else{
                    if(target->parent->left == target) target->parent->left = target->right;
                    else target->parent->right = target->right;
                    target->right->parent = target->parent;
                }
                delete target;
            }
        }

        void search(int v){
            const int N = 1000;
            Node* stack[N];
            int top = -1;
            if(root) stack[++top] = root;
            int comparisons = 0;
            while(top >= 0){
                Node *node = stack[top--];
                comparisons++;
                if(node->val == v){
                    cout << v << " Found with priority " << node->p << ". Comparisons: " << comparisons << ".\n";
                    return;
                }
                if(node->right) stack[++top] = node->right;
                if(node->left) stack[++top] = node->left;
            }
            cout << "Not found. Comparisons: " << comparisons << ".\n";
        }

        void print(){
            inorder(root);
            cout << '\n';
        }          
};

int main(){
    priorityQueue pq;
    pq.enqueue(1, 100);
    pq.enqueue(3, 150);
    pq.enqueue(3, 200);
    pq.enqueue(2, 500);
    pq.enqueue(0, 250);

    pq.print();

    pq.search(500);
    pq.search(300);

    pq.dequeue();

    pq.print();
}