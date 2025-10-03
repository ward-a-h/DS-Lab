#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int n) {
        data = n;
        next = nullptr;
    }
};

void insertAtStart(Node*& head, int n) {
    Node* newNode = new Node(n);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int n) {
    Node* newNode = new Node(n);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtMiddle(Node*& head, int n, int pos) {
    if (pos <= 1) {
        insertAtStart(head, n);
        return;
    }

    Node* newNode = new Node(n);
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        insertAtEnd(head, n);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void bubbleSort(Node*head){
    if (head == nullptr){
        return;
    }
    Node*i;
    Node*j;
    for (i =head; i->next!= nullptr; i =i->next){
        for(j =head; j->next!= nullptr; j =j->next){
            if (j->data> j->next->data){
                swap(j->data, j->next->data);
            }
    }
}
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtStart(head, 25);
    insertAtStart(head, 5);
    insertAtEnd(head, 15);
    insertAtEnd(head, 10);
    insertAtMiddle(head, 30, 3);
    insertAtMiddle(head, 20, 4);

    cout << "Linked List (before sorting): " << endl;
    print(head);
    cout<<endl;

    cout<<"Linked List (after sorting): "<<endl;
    bubbleSort(head);
    print(head);
    cout<<endl;
    return 0;
}