#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};

Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr) root = root->right;
    return root;
}
