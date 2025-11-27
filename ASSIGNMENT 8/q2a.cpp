#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};

Node* bstSearchRecursive(Node* root, int key) {
    if (root == nullptr) return nullptr;
    if (root->data == key) return root;
    if (key < root->data) return bstSearchRecursive(root->left, key);
    return bstSearchRecursive(root->right, key);
}

Node* bstSearchIterative(Node* root, int key) {
    while (root != nullptr && root->data != key) {
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return root; 
}

