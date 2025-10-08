#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void displayList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void reverseList() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;  
            curr->next = prev;  
            prev = curr;        
            curr = next;    
        }

        head = prev;  
        cout << "Linked list reversed.\n";
    }
};

int main() {
    LinkedList list;
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Original linked list: ";
    list.displayList();

    list.reverseList();

    cout << "Reversed linked list: ";
    list.displayList();

    return 0;
}
