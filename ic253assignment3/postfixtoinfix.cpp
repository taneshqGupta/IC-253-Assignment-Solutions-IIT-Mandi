#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node* next;
};

struct Stack {
    Node* top;
    Stack() { top = nullptr; }
    void push(string val) {
        Node* newNode = new Node{val, top};
        top = newNode;
    }
    string pop() {
        if (!top) return "";
        string val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    bool empty() { return top == nullptr; }
    string peek() { return top ? top->data : ""; }
};

string postfixToInfix(string s) {
    Stack st;
    for (char c : s) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            st.push(string(1, c));
        } else {
            string op2 = st.pop();
            string op1 = st.pop();
            string expr = "(" + op1 + " " + c + " " + op2 + ")";
            st.push(expr);
        }
    }
    return st.peek();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;
    cout << "Infix expression: " << postfixToInfix(postfix) << endl;
    return 0;
}

