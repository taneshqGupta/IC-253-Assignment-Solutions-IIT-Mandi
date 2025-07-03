#include <bits/stdc++.h>
using namespace std;

// implementation of BST using linked data structure
// perform insertion, deletion & search
// also report the number of comparisons



class bst{

  struct Node{
    int key;
    Node *left, *right, *parent;
    Node(int val): key(val), left(nullptr), right(nullptr), parent(nullptr) {}
  };
  
  Node* root;

  Node* findMIn(Node* node){
    while(node && node->left){
      node = node->left;
    }
    return node;
  }

  void inorder(Node* node){
    if(!node) return;
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
  }

  public:
  
      bst(): root(nullptr) {}

      int insert(int key){
        int comparisons=0;
        Node* newNode = new Node(key);
        if(!root){
          root = newNode;
          cout << "inserted " << key << " with " << 1 << " comparisons.\n";
          return comparisons;
        }
        Node* curr = root;
        Node* parent = root->parent;
        while(curr){
          parent = curr;
          comparisons++;
          if(key < curr->key) curr = curr->left;
          else curr = curr->right;
        }
        newNode->parent = parent;
        comparisons++;
        if(key <= parent->key) parent->left = newNode;
        else parent->right = newNode;

        cout << "Inserted " << key << " with " << comparisons << " comparisons.\n";
        return comparisons;
      }

      int search(int key){
        int comparisons = 0;
        Node* curr = root;
        while(curr){
          comparisons++;
          if(key == curr->key) {
            cout << "Found " << key << " with " << comparisons << " comparisons.\n";
            return comparisons;
          }
          comparisons++;
          if(key <= curr->key) curr = curr->left;
          else curr = curr->right;
        }
        cout << key << " not found after " << comparisons << " comparisons.\n";
        return comparisons;
      }

      int remove(int key){
        int comparisons = 0;
        Node* curr = root;
        Node* parent = root->parent;
        while(curr && curr->key != key){
          parent = curr;
          comparisons++;
          if(key < curr->key) curr = curr->left;
          else curr = curr->right;
        }
        comparisons++;
        if(!curr){
          cout << key << " not found with " << comparisons << " comparisons.\n";
          return comparisons;
        }
        if(!curr->left || !curr->right){
          Node* child = curr->left ? curr->left : curr->right;
          if(!parent){
            root = child;
          }
          else if(parent->left == curr){
            parent->left = child;
          }
          else{
            parent->right = child;
          }
          if(child) child->parent = parent;
          
          delete curr;
          }
          else{
            Node* succ = findMIn(curr->right);
            int temp = succ->key;
            remove(succ->key);
            curr->key = temp;
          }
          cout << "deleted " << key << " with " << comparisons << " comparisons.\n";
          return comparisons;
        }
      

      void print(){
        inorder(root);
        cout << '\n';
      }

    };
    
    int main() {

      bst tree;
      tree.insert(50);
      tree.insert(30);
      tree.insert(20);
      tree.insert(40);
      tree.insert(70);
      tree.insert(60);
      tree.insert(80);

      tree.print();

      tree.search(40);
      tree.search(90);

      tree.remove(20);
      tree.remove(30);
      tree.remove(50);

      tree.print();


      return 0;
}
