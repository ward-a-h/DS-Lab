#include<iostream>
using namespace std;
int main(){
    int arr[9]={20, 12, 15, 2, 10, 1, 13, 9, 5};
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

     int c=n/2;
    swap(arr[8],arr[c]);
    
     cout<<"Sorted Array with Maximum element in the middle: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}