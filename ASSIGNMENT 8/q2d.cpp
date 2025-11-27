#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* bstSearchIterative(Node* root, int key) {
    while (root && root->data != key) {
        root = (key < root->data) ? root->left : root->right;
    }
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* target = bstSearchIterative(root, key);
    if (!target) return nullptr;

    if (target->right) return findMin(target->right);

    Node* succ = nullptr;
    Node* ancestor = root;
    while (ancestor != nullptr) {
        if (key < ancestor->data) {
            succ = ancestor;
            ancestor = ancestor->left;
        } else if (key > ancestor->data) {
            ancestor = ancestor->right;
        } else {
            break;
        }
    }
    return succ; 
}
