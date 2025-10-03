#include<iostream>
using namespace std;
int main(){
    int arr[]={2022, 2024, 2023, 2022, 2023, 2024, 2022, 2023, 2024};
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
    return 0;
}