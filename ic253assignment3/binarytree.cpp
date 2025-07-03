#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1000;

struct BinaryTreeArray{
  int tree[MAX_SIZE];
  int size;
  BinaryTreeArray(){
    size = 0;
  }

  void insert(int s){
    if(size>=MAX_SIZE) return;
    tree[size] = s;
    size++;
  }

  int search(int s){
    for(int i=0; i<size; i++){
      if(tree[i] == s) return i;
    }
    return -1;
  }

  void deleteNode(int s){
    int index = -1;
    for(int i=0; i<size; i++){
      if(tree[i] == s){
        index = i;
        break;
      }
    }
    if(index==-1) return;

    tree[index] = tree[size-1];
    size--;
  }

  void print(){
    for(int i=0; i<size; i++) cout << tree[i] << ' ';
    cout << '\n';
  }
};

struct BinaryTreeLL{
  struct Node{
    int key;
    Node *left, *right, *parent;
    Node(int val, Node* par = nullptr) : key(val), left(nullptr), right(nullptr), parent(par) {}
  };
  Node* root;
  BinaryTreeLL() : root(nullptr) {}

  void insert(int s){
    if(!root){
      root = new Node(s);
      return;
    }

    Node* a[1000];
    int front = 0, rear = 0;
    a[rear++] = root;
    while(front < rear){
      Node* temp = a[front++];
      if(!temp->left){
        temp->left = new Node(s, temp);
        return;
      } 
      else{
        a[rear++] = temp->left;
      }
      if(!temp->right){
        temp->right = new Node(s, temp);
        return;
      }
      else{
        a[rear++] = temp->right;
      }

    }
  }

  int search(int s){
    if(!root) return -1;
    Node* a[1000];
    int front = 0, rear = 0, index = 0;
    a[rear++] = root;
    while(front<rear){
      Node* temp = a[front++];
      if(temp->key == s) return index;
      if(temp->left) a[rear++] = temp->left;
      if(temp->right) a[rear++] = temp->right;
      index++;
    }
    return -1;
  }

  void deleteNode(int s){
    if(!root) return;
    Node *keyNode = nullptr, *deepest = nullptr;
    Node* a[1000];
    int front = 0, rear = 0;
    a[rear++] = root;
    while(front < rear){
      Node* temp = a[front++];
      if(temp->key == s) keyNode = temp;
      deepest = temp;
      if(temp->left){
        a[rear++] = temp->left;
        temp->left->parent = temp;
      }
      if(temp->right){
        a[rear++] = temp->right;
        temp->right->parent = temp;
      }
    }
    if(!keyNode) return;
    keyNode->key = deepest->key;
    if(deepest->parent){
      if(deepest->parent->left == deepest) deepest->parent->left = nullptr;
      else deepest->parent->right = nullptr;
    }
    else root = nullptr;
    delete deepest;
  }

  void inorder(Node* node){
    if(!node) return;
    inorder(node->left);
    cout << node->key << ' ';
    inorder(node->right);
  }

  void print(){
    inorder(root);
    cout << '\n';
  }

};

int main(){

  BinaryTreeLL tree;
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);

  tree.print();

  cout << tree.search(30) << '\n';
  tree.deleteNode(30);
  cout << tree.search(30) << '\n';
  tree.print();
  
  return 0;
}

