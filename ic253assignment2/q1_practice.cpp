#include <iostream>
using namespace std;


struct LinkedList{

    struct Node{
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
            return;
        }
        newNode -> next = head;
        head = newNode;
    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            tail = newNode;
            return;
        }
        tail -> next = newNode;
        tail = newNode;
    }

    void insertAtPosition(int pos, int val){
        Node* newNode = new Node(val);
        if(pos<=0){
            insertAtHead(val);
            return;
        }
        Node* temp = head;
        for(int i=1; temp && i<pos; i++)
            temp = temp -> next;
        if(!temp || !temp->next){
            insertAtTail(val);
            return;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    void deleteAtHead(){
        if(!head) return;
        Node* temp = head;
        head = head -> next;
        delete temp;
        if(!head) tail = nullptr;
    }

    void deleteAtTail(){
        if(!head) return;
        if(head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp -> next;
        }
        delete tail;
        tail = temp;
        tail -> next = nullptr;
    }

    void deleteAtPosition(int pos){
        if(!head || pos<0) return;
        if(pos == 0){
            deleteAtHead();
            return;
        }
        Node* temp = head;
        for(int i=1; temp->next && i<pos; i++){
            temp = temp -> next;
        }
        if(!temp->next) return;
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        if(!temp->next) tail = temp;
        delete toDelete;
    }

    void printList(){
        Node* temp = head;
        while(temp){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }
};

int main(){
    
    LinkedList a;

    a.insertAtHead(12);
    a.printList();
    a.insertAtPosition(0, 90);
    a.printList();
    a.insertAtTail(0);
    a.printList();
    a.insertAtPosition(2, 5);
    a.printList();
    a.deleteAtHead();
    a.printList();
    a.deleteAtTail();
    a.printList();
    a.deleteAtPosition(1);
    a.printList();
    
    return 0;
}
