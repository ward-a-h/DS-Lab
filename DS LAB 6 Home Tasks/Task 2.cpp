#include<iostream>
#include<stack>
using namespace std;
class Node{
    public: 
    string data;
    Node* next;

    Node(string url){
        data=url;
        next=nullptr;
    }
};

class LinkedList{
    private:
    Node*head;
    public:
    LinkedList(){
        head=nullptr;
    }
    void insert(string url){
        Node* newNode= new Node(url);
        if(head==nullptr){
            head=newNode;
            return;
        }
        Node*temp=head;
        while(temp->next!=nullptr){
            temp= temp->next;
        }
        temp->next= newNode;
    }
    void deleteAtEnd(){
        Node*temp=head;
        Node*prev=nullptr;
        if(temp==nullptr){
            return;
        }
        if(temp->next==nullptr){
            delete head;
            head=nullptr;
            return;
        }
        while(temp->next!=nullptr){
            prev=temp;
            temp=temp->next;
        }
        Node*toDelete=temp;
        delete toDelete;
        prev->next=nullptr;
    }

    void display(){

        Node*temp=head;
        if(temp==nullptr){
            cout<<"No history."<<endl;
            return;
        }
        while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList st;
    stack<string>s;
    int n;
    cout<<"Enter number of websites visited: "<<endl;
    cin>>n;
    string val;
    cout<<"Enter websites visited: "<<endl;
    for(int i=0; i<n; i++){
        cin>>val;
        s.push(val);
        st.insert(val);
    }

    cout<<endl;

    cout<<"Browsing History: "<<endl;
    st.display();

    cout<<endl;

    if(!s.empty()){
        cout<<"Current page:"<<s.top()<<endl;
    }
    else{
        cout<<"No browsing history."<<endl;
    }

    cout<<endl;

    cout<<"Backing up two pages..."<<endl;
    if(!s.empty()){
    s.pop();
    st.deleteAtEnd();
    }
    if(!s.empty()){
    s.pop();
    st.deleteAtEnd();
    }

    cout<<endl;

    cout<<"Updated History: "<<endl;
    st.display();

    cout<<endl;

    if(!s.empty()){
        cout<<"Current page: "<<s.top()<<endl;
    }
    else{
        cout<<"No browsing history."<<endl;
    }

    cout<<endl;
    return 0;
}