#include<iostream>
using namespace std;
void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min_index=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}
int main(){
    int arr[10];
    int n=10;
    cout<<"Enter 10 elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Elements before sorting: "<<endl;
     for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl;

    selectionSort(arr, n);
    cout<<"Elements after sorting: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"The 4 minimum elements are: "<<endl;
    for(int i=0; i<4; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}