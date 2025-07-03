#include <bits/stdc++.h>
using namespace std;

// Singly Linked List
struct SinglyNode {
    int data;
    SinglyNode* next;
};

struct SinglyLinkedList {
    SinglyNode* head;
};

void insertHead(SinglyLinkedList& list, int val) {
    SinglyNode* newNode = new SinglyNode{val, list.head};
    list.head = newNode;
}

void insertTail(SinglyLinkedList& list, int val) {
    SinglyNode* newNode = new SinglyNode{val, nullptr};
    if (!list.head) { list.head = newNode; return; }
    SinglyNode* temp = list.head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void deleteHead(SinglyLinkedList& list) {
    if (!list.head) return;
    SinglyNode* temp = list.head;
    list.head = list.head->next;
    delete temp;
}

void print(SinglyLinkedList& list) {
    SinglyNode* temp = list.head;
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << "\n";
}

// Doubly Linked List
struct DoublyNode {
    int data;
    DoublyNode* prev;
    DoublyNode* next;
};

struct DoublyLinkedList {
    DoublyNode* head;
};

void insertHead(DoublyLinkedList& list, int val) {
    DoublyNode* newNode = new DoublyNode{val, nullptr, list.head};
    if (list.head) list.head->prev = newNode;
    list.head = newNode;
}

void deleteHead(DoublyLinkedList& list) {
    if (!list.head) return;
    DoublyNode* temp = list.head;
    list.head = list.head->next;
    if (list.head) list.head->prev = nullptr;
    delete temp;
}

void print(DoublyLinkedList& list) {
    DoublyNode* temp = list.head;
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << "\n";
}

// Insertion Sort (Array)
void insertionSort(vector<int>& arr) {
    int n = arr.size(), comps = 0, swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comps++, swaps++;
        }
        arr[j + 1] = key;
    }
    cout << "Comparisons: " << comps << ", Swaps: " << swaps << "\n";
}

int main() {
    SinglyLinkedList sll = {nullptr};
    insertHead(sll, 5);
    insertTail(sll, 10);
    print(sll);
    deleteHead(sll);
    print(sll);

    vector<int> arr = {4, 3, 2, 10, 12, 1, 5, 6};
    insertionSort(arr);
    for (int x : arr) cout << x << " ";
    cout << "\n";
    return 0;
}

