#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

struct LinkedList {
    Node* head, *tail;
    
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if(!head){
          head = newNode;
          tail = newNode;
        }
        else{
          tail->next = newNode;
          tail = newNode;
        }
    }

    void findPositions() {
        Node* positions[1000] = {nullptr};  
        Node* current = head;
        int index = 1;

        while (current) {
            for (int i = 1; i <= index; i++) {
                if (index % i == 0) {
                    if (!positions[i - 1]) positions[i - 1] = head;
                    else positions[i - 1] = positions[i - 1]->next;
                }
            }
            current = current->next;
            index++;
        }

        for (int i = 1; positions[i]; i++) {
            cout << "Element at n/" << i + 1 << ": " << positions[i]->data << endl;
        }
    }
};

int main() {
    LinkedList ll;
    int x;
    cin >> x;
    while(x--){
      int val;
      cin >> val;
      ll.insert(val);
    }
    ll.findPositions();
    return 0;
}
