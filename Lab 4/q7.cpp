#include<iostream>
#include<string>
using namespace std;
int main(){
    string arr[]={"Ahmed", "Ali", "Basit", "Karim", "Rizwan", "Sarwar", "Tariq", "Taufiq", "Yasin", "Zulfiqar"};
    int n=sizeof(arr)/sizeof(arr[0]);
    //Binary Search
    int left=0;
    int right=n-1;
    bool found1=false;

    string k1="Aftab";
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==k1){
            found1=true;
            cout<<"Aftab was found"<<endl;
            break;
        }
        else if(arr[mid]<k1){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
     bool found2=false;
     left=0;
     right=n-1;
     string k2="Tariq";
     while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==k2){
            found2=true;
            cout<<"Tariq was found"<<endl;
            break;
        }
        else if(arr[mid]<k2){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    left=0;
    right=n-1;
    bool found3=false;
    string k3="Rizwan";
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==k3){
            found3=true;
            cout<<"Rizwan was found"<<endl;
            break;
        }
        else if(arr[mid]<k3){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    if(!found1){
        cout<<"Aftab wasn't found"<<endl;
    }
     if(!found2){
        cout<<"Tariq wasn't found"<<endl;
    }
     if(!found3){
        cout<<"Rizwan wasn't found"<<endl;
    }
    return 0;
}