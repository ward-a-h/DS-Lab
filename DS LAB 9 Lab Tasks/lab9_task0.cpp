//Why AVL? AVL are normal binary search trees that are balanced. 
//By keeping the balance, the insertion and deleltion functions 
//reduce the time complexity. 

//Coverting BST into AVL

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:

    int data;
    Node*left;
    Node*right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
Node*insert(Node*root, int d){
    if(root==NULL){
        return new Node(d);
    }
    if(d<root->data){
        root->left=insert(root->left, d);
    }
    else{
        root->right=insert(root->right, d);
    }
    return root;
}

Node*enterData(Node*root){
    int data;
    cout<<"Enter data(-1 if you want to stop): "<<endl;
    cin>>data;
    while(data!=-1){
        root=insert(root, data);
        cout<<"Enter data(-1 to stop): "<<endl;
        cin>>data;
    }
    return root;
}

void inorderTraversal(Node*root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right); 
}

void storeTraversal(Node*root, vector<int>&arr){
    if(root==NULL){
        return;
    }
    storeTraversal(root->left, arr);
    arr.push_back(root->data);
    storeTraversal(root->right, arr);
}

Node*buildAVL(vector<int>&arr, int s, int e){
    if(s>e){
        return NULL;
    }
    int middle=(s+e)/2;
    Node*root= new Node(arr[middle]);

    root->left=buildAVL(arr, s, middle-1);
    root->right=buildAVL(arr, middle+1, e);

    return root;
}
int main(){
    Node*root=NULL;
    vector<int>arr;
    root=enterData(root);
    storeTraversal(root, arr);
    Node*create=buildAVL(arr, 0, arr.size()-1);
    cout<<"Inorder traversal of AVL: "<<endl;
    inorderTraversal(create);
}

/*Nodes are linked recursively: each root->left and root->right
 points to balanced subtrees built from the array halves.
Temporary pointers like x, y, t2 are not needed because the
 middle-element method ensures automatic balancing.
Each new node corresponds in value to an original BST node, 
but is a fresh object.
The function returns the root of the subtree 
(or entire AVL at the top) so the parent nodes can link correctly.
*/