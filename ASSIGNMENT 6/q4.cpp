#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(char val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    bool isPalindrome() {
        if (head == NULL || head->next == NULL)
            return true; 

        Node* left = head;
        Node* right = head;

        while (right->next != NULL)
            right = right->next;

        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }

        return true;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int n;
    char ch;
    cout << "Enter number of characters: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter character " << i + 1 << ": ";
        cin >> ch;
        dll.insertAtEnd(ch);
    }

    dll.display();
    
    if (dll.isPalindrome())
        cout << "The Doubly Linked List is a Palindrome.\n";
    else
        cout << "The Doubly Linked List is NOT a Palindrome.\n";

    return 0;
}
