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
    if (N == NULL) {
        return -1;
    } else {
        return N->height;
    }
}

void updateHeight(Node* N) {
    int left_h = getHeight(N->left);
    int right_h = getHeight(N->right);
    if (left_h > right_h) {
        N->height = 1 + left_h;
    } else {
        N->height = 1 + right_h;
    }
}

int balanceFactor(Node* N) {
    if (N == NULL) {
        return 0;
    } else {
        return getHeight(N->left) - getHeight(N->right);
    }
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
    if (node == NULL) {
        return new Node(key);
    }
    if (key < node->data) {
        node->left = insert(node->left, key);
    } else if (key > node->data) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    updateHeight(node);
    int balance = balanceFactor(node);

    if (balance > 1 && key < node->left->data) {
        return rotateRight(node);
    }
    if (balance > 1 && key > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key > node->right->data) {
        return rotateLeft(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inorderTraversal(Node* root, int &count, int k, int &kthSmall) {
    if (root == NULL) {
        return;
    } else {
        inorderTraversal(root->left, count, k, kthSmall);
        count = count + 1;
        if (count == k) {
            kthSmall = root->data;
        }
        inorderTraversal(root->right, count, k, kthSmall);
    }
}

void reverseInorderTraversal(Node* root, int &count, int k, int &kthLarge) {
    if (root == NULL) {
        return;
    } else {
        reverseInorderTraversal(root->right, count, k, kthLarge);
        count = count + 1;
        if (count == k) {
            kthLarge = root->data;
        }
        reverseInorderTraversal(root->left, count, k, kthLarge);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);

    int k = 3;
    int count = 0;
    int kthSmall = -1;
    inorderTraversal(root, count, k, kthSmall);

    count = 0;
    int kthLarge = -1;
    reverseInorderTraversal(root, count, k, kthLarge);

    cout <<"smallest: " << kthSmall << endl;
    cout <<"largest: " << kthLarge << endl;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    cout << "Left subtree height from root: " << leftHeight << endl;
    cout << "Right subtree height from root: " << rightHeight << endl;

    return 0;
}