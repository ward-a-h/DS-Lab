#include<iostream>
using namespace std;
int main(){
    //Roll number: 25K-0534
    //I'll be using 34 in the array
    //I couldn't find the array in the Binary Search header so I'm 
    //just using a prev array and inserting 34 in the middle. 
    
    int arr[10]={20, 12, 15, 2, 10, 34, 1, 13, 9, 5};
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
    int roll_no=34;
    int left=0;
    int right=n-1;
    bool found=false;
    while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == roll_no) {
        cout<<"Last 2 digits of roll no."<< roll_no <<" found at index: "<<mid<<endl;
        found=true;
        break;
    }
    else if (arr[mid] < roll_no) {
    left = mid + 1;
    }
    else {
    right = mid - 1;
    }
}
    if(!found){
        cout<<"Last 2 digits of roll no. not found. Sorry!"<<endl;
    }
    return 0;
}


