#include<iostream>
using namespace std;
int main(){
    int arr[12]={20, 2, 12, 15, 2, 10, 1, 5, 13, 9, 1, 5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted Array: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=1; i<n; i++){
        int key= arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;

    }
    cout<<"Sorted Array through insertion sorting: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Checking for duplicates: "<<endl;
    bool duplicates=false;
    for(int i=0; i<n-1; i++){
            if(arr[i]==arr[i+1]){
                duplicates=true;
                break;
            }
         }
    if(duplicates){
        cout<<"Array contains duplicates!"<<endl;
    }
    else{
        cout<<"Array doesn't contain duplicates!"<<endl;
    }
          return 0;
}