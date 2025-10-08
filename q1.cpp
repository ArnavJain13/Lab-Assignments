#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear;
    int MAX;

public:
    Queue(int size) {
        MAX = size;
        arr = new int[MAX];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue overflow " << x << endl;
            return;
        }

        if (isEmpty()) front = 0;
        arr[++rear] = x;
        cout << x << "Enqueue done\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return;
        }

        cout << arr[front] << "Dequeue done \n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue empty \n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue empty.\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter maximum size of the queue: ";
    cin >> size;

    Queue q(size);
    int choice = -1, value;

    while (choice != 0) {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.peek();
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 5) {
            cout << (q.isEmpty() ? "Queue empty.\n" : "Queue not empty.\n");
        }
        else if (choice == 6) {
            cout << (q.isFull() ? "Queue full.\n" : "Queue not full.\n");
        }
        else if (choice == 0) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
