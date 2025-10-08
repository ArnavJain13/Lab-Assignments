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
            cout << "Queue overflow \n";
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow \n";
            return -1;
        }
        int x = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return x;
    }

    int size() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue empty \n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int getAt(int index) {
        return arr[front + index];
    }

    void setAt(int index, int value) {
        arr[front + index] = value;
    }
};


void interleaveQueue(Queue &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue must have even number of elements.\n";
        return;
    }

    int half = n / 2;
    int* firstHalf = new int[half];

    for (int i = 0; i < half; i++) {
        firstHalf[i] = q.dequeue();
    }

    for (int i = 0; i < half; i++) {
        q.enqueue(firstHalf[i]);  
        int temp = q.dequeue();    
        q.enqueue(temp);
    }

    delete[] firstHalf;
}

int main() {
    int n, x;
    cout << "Enter even number of elements: ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Enter even number of elements.\n";
        return 0;
    }

    Queue q(n);     

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    cout << "\nOriginal ";
    q.display();

    interleaveQueue(q);

    cout << "Interleaved ";
    q.display();

    return 0;
}
