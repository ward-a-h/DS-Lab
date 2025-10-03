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

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void mergeList(Node*&head1, Node*&head2){
    Node*temp1=head1;
    Node*temp2=head2;
    Node*next1;
    Node*next2;

    while(temp1!=nullptr && temp2!=nullptr){
        next1 = temp1->next;
        next2 = temp2->next;

        temp1->next = temp2;
        temp2->next = next1;

        temp1 = next1;
        temp2 = next2;

        head2 = temp2;
    }
}
int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;


    insertAtStart(head1, 1);
    insertAtEnd(head1, 3);
    insertAtMiddle(head1, 2, 2);

    insertAtStart(head2, 4);
    insertAtEnd(head2, 8);
    insertAtMiddle(head2, 5, 2);
    insertAtMiddle(head2, 6, 3);
    insertAtMiddle(head2, 7, 4);



    cout << "Linked Lists (before merging): " << endl;
    cout<<"LinkedList 1: "<<endl;
    print(head1);
    cout<<"Linked List 2: "<<endl;
    print(head2);
    cout<<endl;

    cout<<"Linked Lists (after merging): "<<endl;
    mergeList(head1, head2);
    cout<<"Linked List 1: "<<endl;
    print(head1);
    cout<<"Linked List 2: "<<endl;
    print(head2);

    return 0;
}