#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

bool isBSTInorder(Node* root, long long &prev) {
    if (root == nullptr)
        return true;

    if (!isBSTInorder(root->left, prev))
        return false;

    if (root->data <= prev)
        return false;

    prev = root->data;

    return isBSTInorder(root->right, prev);
}

bool isBST(Node* root) {
    long long prev = LLONG_MIN; 
    return isBSTInorder(root, prev);
}

int main() {

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    if (isBST(root))
        cout << "Tree is a BST\n";
    else
        cout << "Tree is NOT a BST\n";

    return 0;
}
