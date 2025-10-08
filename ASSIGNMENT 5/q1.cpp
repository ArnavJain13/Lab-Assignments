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

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at beginning.\n";
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
        cout << value << " inserted at end.\n";
    }

    void insertBeforeAfter(int value, int target, bool after = true) {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }

        Node* newNode = new Node(value);

        if (after) {
            Node* temp = head;
            while (temp != nullptr && temp->data != target)
                temp = temp->next;
            if (temp == nullptr) {
                cout << "Target node " << target << " not found.\n";
                delete newNode;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            cout << value << " inserted after " << target << ".\n";
        } else {
            if (head->data == target) {
                insertAtBeginning(value);
                return;
            }
            Node* prev = head;
            Node* curr = head->next;
            while (curr != nullptr && curr->data != target) {
                prev = curr;
                curr = curr->next;
            }
            if (curr == nullptr) {
                cout << "Target node " << target << " not found.\n";
                delete newNode;
                return;
            }
            newNode->next = curr;
            prev->next = newNode;
            cout << value << " inserted before " << target << ".\n";
        }
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning.\n";
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            cout << head->data << " deleted from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        cout << temp->next->data << " deleted from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value)
            temp = temp->next;
        if (temp->next == nullptr) {
            cout << "Node " << value << " not found.\n";
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        cout << delNode->data << " deleted.\n";
        delete delNode;
    }

    void searchNode(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << value << " not found in the list.\n";
    }

    void displayList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, value, target;
    bool after;

    do {
        cout << "\n1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before/after a node\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete a specific node\n";
        cout << "7. Search a node\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
        } 
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
        } 
        else if (choice == 3) {
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter target node value: ";
            cin >> target;
            cout << "Insert after target? (1 for Yes, 0 for No): ";
            cin >> after;
            list.insertBeforeAfter(value, target, after);
        } 
        else if (choice == 4) {
            list.deleteFromBeginning();
        } 
        else if (choice == 5) {
            list.deleteFromEnd();
        } 
        else if (choice == 6) {
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
        } 
        else if (choice == 7) {
            cout << "Enter value to search: ";
            cin >> value;
            list.searchNode(value);
        } 
        else if (choice == 8) {
            list.displayList();
        } 
        else if (choice == 9) {
            cout << "Exiting program.\n";
        } 
        else {
            cout << "Invalid choice\n";
        }

    } while (choice != 9);

    return 0;
}
