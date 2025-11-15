#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
        height = 0;
    }
};

int getHeight(Node* N) {
    if (N == NULL)
        return -1;
    return N->height;
}

void updateHeight(Node* N) {
    int left_h = getHeight(N->left);
    int right_h = getHeight(N->right);
    N->height = 1 + max(left_h, right_h);
}

int balanceFactor(Node* N) {
    if (N == NULL) return 0;
    return getHeight(N->left) - getHeight(N->right);
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* insert(Node* node, int key) {
    if (node == NULL)
        return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    updateHeight(node);
    int balance = balanceFactor(node);

    if (balance > 1 && key < node->left->data)
        return rotateRight(node);
    if (balance > 1 && key > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key > node->right->data)
        return rotateLeft(node);
    if (balance < -1 && key < node->right->data) {
        node->right = rotateRight(node->right);
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

void printBalance(Node* root) {
    if (root == NULL) return;
    printBalance(root->left);
    cout << "Node: " << root->data << ", Balance Factor: " << balanceFactor(root) << ", Height: " << root->height << endl;
    printBalance(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);

    cout << "Inorder traversal of final AVL tree: ";
    inorderTraversal(root);
    cout << endl;

    cout << "\nBalance factors and heights:" << endl;
    printBalance(root);

    cout << "\nHeight of the AVL tree: " << root->height << endl;

    return 0;
}