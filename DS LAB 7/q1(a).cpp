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

void deleteFromStart(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd(Node*& head) {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void deleteFromMiddle(Node*& head, int pos) {
    if (head == nullptr || pos <= 1) {
        deleteFromStart(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        return;
    }

    Node* temp1 = temp->next;
    temp->next = temp->next->next;
    delete temp1;
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

    insertAtStart(head, 10);
    insertAtStart(head, 5);
    insertAtEnd(head, 25);
    insertAtEnd(head, 30);
    insertAtMiddle(head, 15, 3);
    insertAtMiddle(head, 20, 4);

    cout << "Before Deleting: " << endl;
    print(head);

    deleteFromStart(head);
    cout << "After deleting (from start):" << endl;
    print(head);

    deleteFromEnd(head);
    cout << "After deleting (from end):" << endl;
    print(head);

    deleteFromMiddle(head, 3);
    cout << "After deleting (from middle):" << endl;
    print(head);

    return 0;
}