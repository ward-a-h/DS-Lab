#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<string>toDoList;
    int n;
    string val;
    cout<<"Enter size of list: "<<endl;
    cin>>n;
    cout<<"Enter items: "<<endl;
    for(int i=0; i<n; i++){
        cin>>val;
        toDoList.push(val);
    }
    stack<string>copy=toDoList;
    while(!copy.empty()){
    cout<<"\nPrinting original list: "<<endl;
    for(int i=0; i<n; i++){
        cout<<" "<<copy.top();
        copy.pop();
    }
}
    cout<<"\nAdding a new item to the list: "<<endl;
    cin>>val;
    toDoList.push(val);
    
    cout<<"\nRemoving top item from the list...."<<endl;
    toDoList.pop();
    
    cout<<"\nViewing top item of the list: "<<toDoList.top()<<endl;

    cout<<"\nChecking if list is empty: "<<endl;
    if(toDoList.empty()){
        cout<<"List Empty"<<endl;
    }
    else{
        cout<<"List not empty"<<endl;
    }
    cout<<"Updated List:"<<endl;
    stack<string>s=toDoList;
    while(!s.empty()){
    for(int i=0; i<n; i++){
        cout<<" "<<s.top();
        s.pop();
    }
}
cout<<endl;
return 0;

}