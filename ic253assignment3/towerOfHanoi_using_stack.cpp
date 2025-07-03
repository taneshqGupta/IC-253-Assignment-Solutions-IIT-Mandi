#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
};

struct Stack{
  Node* top;
  Stack() { top = nullptr; };

  void push(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
  }

  int pop(){
    if(top == nullptr) return INT_MIN;
    int data = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return data;
  }

  int peek(){
    return (top ? top->data : INT_MIN);
  }

  bool isEmpty(){
    return top==nullptr;
  }

  void print(){
    Node* curr = top;
    while(curr != nullptr){
      cout << curr->data << ' ';
      curr = curr->next;
    }
    cout << '\n';
  }
};

void MoveDisk(Stack &src, Stack &dest, char s, char d){
  int disk = src.pop();
  dest.push(disk);
  cout << "moved disk valued " << disk << " from " << s << " to " << d << '\n';
}

void TowerOfHanoi(int n, Stack &src, Stack &aux, Stack &dest, char s, char a, char d){
  if(n==1){
    MoveDisk(src, dest, s, d);
    return;
  }

  TowerOfHanoi(n-1, src, dest, aux, s, d, a);
  MoveDisk(src, dest, s, d);
  TowerOfHanoi(n-1, aux, src, dest, a, s, d);
}

int main(){
  int n;
  cin >> n;
  Stack src, aux, dest;
  for(int i=n; i>=1; i--) src.push(i);
  src.print();
  aux.print();
  dest.print();
  TowerOfHanoi(n, src, aux, dest, 'A', 'B', 'C');
  src.print();
  aux.print();
  dest.print();
  return 0;
}
