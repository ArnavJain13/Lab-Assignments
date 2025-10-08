#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear, MAX;

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
            cout << "Queue Overflow!\n";
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return val;
    }

    int size() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }

    int frontElement() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Stack implemented using ONE Queue
class Stack {
    Queue q;
public:
    Stack(int size) : q(size) {}

    void push(int x) {
        if (q.isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }

        int n = q.size();
        q.enqueue(x);

        // Rotate the queue elements (bring new element to front)
        for (int i = 0; i < n; i++) {
            int temp = q.dequeue();
            q.enqueue(temp);
        }
        cout << x << " pushed onto stack.\n";
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        cout << q.dequeue() << " popped from stack.\n";
    }

    void top() {
        if (q.isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top element: " << q.frontElement() << endl;
        }
    }

    void display() {
        if (q.isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack elements (top to bottom): ";
        q.display();
    }
};

int main() {
    int size, choice = -1, value;
    cout << "Enter maximum size of the stack: ";
    cin >> size;

    Stack s(size);

    while (choice != 0) {
        cout << "\n===== STACK USING ONE QUEUE =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
        }
        else if (choice == 2) {
            s.pop();
        }
        else if (choice == 3) {
            s.top();
        }
        else if (choice == 4) {
            s.display();
        }
        else if (choice == 0) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
