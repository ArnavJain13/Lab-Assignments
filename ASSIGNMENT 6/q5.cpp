#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void makeCircular() {
        if (head == NULL)
            return;
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head;  
    }

    bool isCircular() {
        if (head == NULL)
            return false;

        Node* temp = head->next;
        while (temp != NULL && temp != head)
            temp = temp->next;

        return (temp == head);
    }

    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value of node " << i + 1 << ": ";
        cin >> val;
        list.insertAtEnd(val);
    }
    cout << "\nDo you want to make it circular? (1 for Yes / 0 for No): ";
    int choice;
    cin >> choice;
    if (choice == 1)
        list.makeCircular();

    if (list.isCircular())
        cout << "\nThe Linked List is Circular.\n";
    else
        cout << "\nThe Linked List is NOT Circular.\n";

    return 0;
}
