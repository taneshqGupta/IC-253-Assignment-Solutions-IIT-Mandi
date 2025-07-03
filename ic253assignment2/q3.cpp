#include <bits/stdc++.h>
using namespace std;

struct CircularLinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    CircularLinkedList() : head(nullptr) {}

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAtPosition(int pos, int val) {
        if (pos <= 0) {
            insertAtHead(val);
            return;
        }
        Node* temp = head;
        for (int i = 1; temp->next != head && i < pos; i++)
            temp = temp->next;
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtHead() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        delete temp;
    }

    void deleteAtTail() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != head)
            temp = temp->next;
        delete temp->next;
        temp->next = head;
    }

    void deleteAtPosition(int pos) {
        if (!head || pos < 0) return;
        if (pos == 0) {
            deleteAtHead();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp->next != head && i < pos; i++)
            temp = temp->next;
        if (temp->next == head) return;
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void printKElements(int k) {
        Node* temp = head;
        for (int i = 0; temp && i < k; i++) {
            cout << temp->data << " ";
            temp = temp->next;
            if (temp == head) break;
        }
        cout << "\n";
    }

    void printCircularFromK(int k) {
        if (!head) return;
        Node* temp = head;
        for (int i = 0; temp && i < k; i++)
            temp = temp->next;
        Node* start = temp;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != start);
        cout << "\n";
    }
};

int main() {
    CircularLinkedList list;
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtPosition(1, 15);
    list.printKElements(3);
    list.deleteAtHead();
    list.printKElements(3);
    list.deleteAtTail();
    list.printKElements(3);
    list.deleteAtPosition(0);
    list.printKElements(3);
    return 0;
}

