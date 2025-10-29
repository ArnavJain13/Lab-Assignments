#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
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

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
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
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != NULL)
                    temp->next->prev = newNode;
                temp->next = newNode;
                cout << "Inserted " << val << " after " << key << ".\n";
                return;
            }
            temp = temp->next;
        }
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
        while (temp != NULL) {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
                cout << "Inserted " << val << " before " << key << ".\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Node " << key << " not found!\n";
    }

    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;

        if (head->data == key) {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
            cout << "Node " << key << " deleted.\n";
            return;
        }

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node " << key << " not found!\n";
            return;
        }

        if (temp->next == NULL) {
            temp->prev->next = NULL;
            delete temp;
            cout << "Node " << key << " deleted.\n";
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        cout << "Node " << key << " deleted.\n";
    }

    void searchNode(int key) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found!\n";
    }

    void displayForward() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        cout << "Doubly Linked List (Forward): ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void displayBackward() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        cout << "Doubly Linked List (Backward): ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, val, key;

    do {
        cout << "\n===== Doubly Linked List Menu =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search for a Node\n";
        cout << "7. Display (Forward)\n";
        cout << "8. Display (Backward)\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                dll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                dll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter key (after which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                dll.insertAfter(key, val);
                break;
            case 4:
                cout << "Enter key (before which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                dll.insertBefore(key, val);
                break;
            case 5:
                cout << "Enter node value to delete: ";
                cin >> key;
                dll.deleteNode(key);
                break;
            case 6:
                cout << "Enter node value to search: ";
                cin >> key;
                dll.searchNode(key);
                break;
            case 7:
                dll.displayForward();
                break;
            case 8:
                dll.displayBackward();
                break;
            case 9:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
