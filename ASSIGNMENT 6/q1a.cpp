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

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
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

    void insertAfter(int key, int val) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Node " << key << " not found!\n";
    }

    void insertBefore(int key, int val) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp;
                prev->next = newNode;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Node " << key << " not found!\n";
    }

    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        if (head->data == key && head->next == head) {
            delete head;
            head = NULL;
            cout << "Node " << key << " deleted.\n";
            return;
        }

        if (head->data == key) {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = head->next;
            Node* delNode = head;
            head = head->next;
            delete delNode;
            cout << "Node " << key << " deleted.\n";
            return;
        }

        do {
            prev = curr;
            curr = curr->next;
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                cout << "Node " << key << " deleted.\n";
                return;
            }
        } while (curr != head);

        cout << "Node " << key << " not found!\n";
    }

    void searchNode(int key) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);

        cout << "Node " << key << " not found!\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};

int main() {
    CircularLinkedList cll;
    int choice, val, key;

    do {
        cout << "\n===== Circular Linked List Menu =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search for a Node\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                cll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                cll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter key (after which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                cll.insertAfter(key, val);
                break;
            case 4:
                cout << "Enter key (before which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                cll.insertBefore(key, val);
                break;
            case 5:
                cout << "Enter node value to delete: ";
                cin >> key;
                cll.deleteNode(key);
                break;
            case 6:
                cout << "Enter node value to search: ";
                cin >> key;
                cll.searchNode(key);
                break;
            case 7:
                cll.display();
                break;
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
