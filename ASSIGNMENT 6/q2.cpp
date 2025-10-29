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

    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        cout << "Output: ";

        while (true) {
            cout << temp->data << " ";
            temp = temp->next;
            if (temp == head) 
                break;
        }

        cout << head->data << endl; 
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);
    cll.display();
    return 0;
}
