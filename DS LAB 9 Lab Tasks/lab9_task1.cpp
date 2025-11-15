#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    int height;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
        height=0;
    }
};

int getHeight(Node*N){
    if(N==NULL){
        return -1;
    }
    return N->height;
}
void updateHeight(Node*N){
    int left_h=getHeight(N->left);
    int right_h=getHeight(N->right);
    int max_h;
    if(left_h>right_h){
        max_h=left_h;
    }
    else{
        max_h=right_h;
    }
    N->height=1+max_h;
}
int balanceFactor(Node*N){
    if(N==NULL){
        return 0;
    }
    return getHeight(N->left)-getHeight(N->right);
}
Node*rotateRight(Node*y){
    Node*x=y->left;
    Node*T2=x->right;
    x->right=y;
    y->left=T2;;
    updateHeight(y);
    updateHeight(x);
    return x;
}
Node*rotateLeft(Node*x){
     Node*y=x->right;
    Node*T2=y->left;
    y->left=x;
    x->right=T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}
Node*insert(Node*node, int key){
    if(node==NULL){
        return new Node(key);
    }
    if(key<node->data){
        node->left=insert(node->left, key);
    }
    else if(key>node->data){
        node->right=insert(node->right, key);
    }
    else{
        return node;
    }
    updateHeight(node);
    int balance=balanceFactor(node);
    if(balance>1&&key<node->left->data){
        return rotateRight(node);
    }
    if(balance>1&&key>node->left->data){
        node->left=rotateLeft(node->left);
        return rotateRight(node);
    }
    if(balance<-1&&key<node->right->data){
        node->right=rotateRight(node->right);
        return rotateLeft(node);
    }
    if(balance<-1&&key>node->right->data){
        return rotateLeft(node);
    }
    return node;
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


int main(){
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    cout << "Inorder traversal of AVL: ";
    inorderTraversal(root);
    cout << endl;


    root = insert(root, 15); // new student

    cout << "Inorder traversal of AVL: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

//Height before inserting 15=2
//Height after inserting 15=2 (no rotations required)


