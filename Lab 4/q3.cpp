#include<iostream>
#include<cstring>
using namespace std;

int main(){
string arr[]={"banana", "apple", "cherry", "date", "grape"};
int n= sizeof(arr)/sizeof(arr[0]);
cout<<"String Array Before Sorting: "<<endl;
for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
for(int i=0; i<n; i++){
    for (int j=0; j<n-1; j++){
        if(arr[j]>arr[j+1]){
            /*string temp= arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            */
           swap(arr[j],arr[j+1]);
        }
    }
}
cout<<"String Array After Sorting: "<<endl;
for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}