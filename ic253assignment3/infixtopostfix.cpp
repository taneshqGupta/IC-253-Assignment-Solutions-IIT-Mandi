#include <bits/stdc++.h>
using namespace std;

struct Stack {
    char arr[100];
    int top;
    Stack() { top = -1; }
    void push(char c) { if (top < 99) arr[++top] = c; }
    char pop() { return (top >= 0) ? arr[top--] : '\0'; }
    char peek() { return (top >= 0) ? arr[top] : '\0'; }
    bool empty() { return top == -1; }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

string infixToPostfix(string s) {
    Stack st;
    string postfix;
    for (char c : s) {
        if (isOperand(c)) {
            postfix += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(st.peek()) >= precedence(c)) {
                postfix += st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix += st.pop();
    }
    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}

