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

class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head; 
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    int getSize() {
        if (head == NULL)
            return 0;

        int count = 0;
        Node* temp = head;

        while (true) {
            count++;
            temp = temp->next;
            if (temp == head)
                break;
        }

        return count;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        while (true) {
            cout << temp->data << " -> ";
            temp = temp->next;
            if (temp == head)
                break;
        }
        cout << "(head)\n";
    }
};

int main() {
    CircularLinkedList cll;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        cll.insertAtEnd(val);
    }
    cll.display();
    cout << "Size of Circular Linked List = " << cll.getSize() << endl;
    return 0;
}
