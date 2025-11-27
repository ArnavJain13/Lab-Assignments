#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* bstSearchIterative(Node* root, int key) {
    while (root && root->data != key) {
        root = (key < root->data) ? root->left : root->right;
    }
    return root;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* target = bstSearchIterative(root, key);
    if (!target) return nullptr;

    if (target->left) return findMax(target->left);

    Node* pred = nullptr;
    Node* ancestor = root;
    while (ancestor != nullptr) {
        if (key > ancestor->data) {
            pred = ancestor;
            ancestor = ancestor->right;
        } else if (key < ancestor->data) {
            ancestor = ancestor->left;
        } else {
            break;
        }
    }
    return pred; 
}
