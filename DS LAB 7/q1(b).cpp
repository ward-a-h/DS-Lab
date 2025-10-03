#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int n) {
        data = n;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL {
private:
    Node* head;

public:
    DLL() {
        head = nullptr;
    }

    void insertAtStart(int n) {
        Node* newNode = new Node(n);
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int n) {
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
        newNode->prev = temp;
    }

    void insertAtMiddle(int n, int pos) {
        if (pos <= 1) {
            insertAtStart(n);
            return;
        }

        Node* newNode = new Node(n);
        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr || temp->next == nullptr) {
            insertAtEnd(n);
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void print(Node* node) {
        while (node != nullptr) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    void printRecursive(Node* node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        printRecursive(node->next);
    }

    Node* reverseRecursive(Node* node) {
        if (node == nullptr)
            return nullptr;

        // Swap next and prev
        Node* temp = node->next;
        node->next = node->prev;
        node->prev = temp;

        // If prev is NULL, it's the new head
        if (node->prev == nullptr)
            return node;

        return reverseRecursive(node->prev);
    }

    void reverse() {
        head = reverseRecursive(head);
    }

    Node* getHead() {
        return head;
    }
};

int main() {
    DLL v;

    v.insertAtStart(10);
    v.insertAtStart(5);
    v.insertAtEnd(25);
    v.insertAtEnd(30);
    v.insertAtMiddle(15, 3);
    v.insertAtMiddle(20, 4);

    cout << "Original List:" << endl;
    v.print(v.getHead());

    v.reverse();

    cout << "Reversed List (Recursive):" << endl;
    v.print(v.getHead());

    return 0;
}
