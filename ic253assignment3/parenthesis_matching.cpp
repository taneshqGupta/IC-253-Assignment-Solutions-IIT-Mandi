#include <bits/stdc++.h>
using namespace std;

struct Node{
  char data;
  Node* next;
  Node(char c) : data(c), next(nullptr) {}
};

struct Stack{
  Node* top;
  Stack() : top(nullptr) {}

  void push(char c){
    Node* newNode = new Node(c);
    newNode->next = top;
    top = newNode;
  }

  char pop(){
    if(top == nullptr) return '\0';
    char res = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return res;
  }

  char peek(){
    if(top == nullptr) return '\0';
    char res = top->data;
    return res;
  }

  bool isEmpty(){
    return top == nullptr;
  }
};

bool isMatching(char open, char close){
  return ((open == '(' && close == ')') || 
          (open == '{' && close == '}') || 
          (open == '[' && close == ']'));
}

bool balanced(string s){
  Stack st;
  for(char c : s){
    if(c == '(' || c == '{' || c == '['){
      st.push(c);
    } else 
    if(c == ')' || c == '}' || c == ']'){
      if(st.isEmpty() || !isMatching(st.peek(), c)){
        return false;
      }
      st.pop();
    }
  }
  return st.isEmpty();
}

int main(){
  string s;
  cin >> s;
  cout << (balanced(s) ? "balanced" : "not balanced") << '\n';
  return 0;
}
