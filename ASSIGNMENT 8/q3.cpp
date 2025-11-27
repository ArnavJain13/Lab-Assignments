#include <iostream>
#include <algorithm>
using namespace std;

class BST {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };
    Node* root;

    Node* insertRec(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insertRec(node->left, key);
        else if (key > node->key)
            node->right = insertRec(node->right, key);
        
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* removeRec(Node* node, int key) {
        if (!node) return nullptr;
        if (key < node->key) {
            node->left = removeRec(node->left, key);
        } else if (key > node->key) {
            node->right = removeRec(node->right, key);
        } else {
           
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            } else if (!node->left) {
                Node* tmp = node->right;
                delete node;
                return tmp;
            } else if (!node->right) {
                Node* tmp = node->left;
                delete node;
                return tmp;
            } else {
                Node* succ = findMin(node->right);
                node->key = succ->key;
                node->right = removeRec(node->right, succ->key);
            }
        }
        return node;
    }

    int maxDepthRec(Node* node) const {
        if (!node) return 0;
        int l = maxDepthRec(node->left);
        int r = maxDepthRec(node->right);
        return 1 + max(l, r);
    }

    int minDepthRec(Node* node) const {
        if (!node) return 0;
        
        if (!node->left && node->right)
            return 1 + minDepthRec(node->right);
        if (node->left && !node->right)
            return 1 + minDepthRec(node->left);
        
        return 1 + min(minDepthRec(node->left), minDepthRec(node->right));
    }

    void inorderRec(Node* node) const {
        if (!node) return;
        inorderRec(node->left);
        cout << node->key << " ";
        inorderRec(node->right);
    }

    void freeRec(Node* node) {
        if (!node) return;
        freeRec(node->left);
        freeRec(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}
    ~BST() { freeRec(root); }

    void insert(int key) { root = insertRec(root, key); }

    void remove(int key) { root = removeRec(root, key); }

    int maxDepth() const { return maxDepthRec(root); }

    int minDepth() const { return minDepthRec(root); }

    void inorder() const {
        inorderRec(root);
        cout << "\n";
    }

    bool empty() const { return root == nullptr; }
};

int main() {
    BST tree;

    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : vals) tree.insert(v);

    cout << "Inorder traversal after inserts: ";
    tree.inorder(); 

    cout << "Max depth (height): " << tree.maxDepth() << "\n";
    cout << "Min depth: " << tree.minDepth() << "\n";

    cout << "Insert duplicate 30 (ignored)\n";
    tree.insert(30);
    cout << "Inorder: ";
    tree.inorder();

    cout << "Remove 20 (leaf)\n";
    tree.remove(20);
    cout << "Inorder: ";
    tree.inorder();

    cout << "Remove 30 (has one child after previous removal)\n";
    tree.remove(30);
    cout << "Inorder: ";
    tree.inorder();

    cout << "Remove 50 (root with two children)\n";
    tree.remove(50);
    cout << "Inorder: ";
    tree.inorder();

    cout << "Max depth now: " << tree.maxDepth() << "\n";
    cout << "Min depth now: " << tree.minDepth() << "\n";

    return 0;
}
