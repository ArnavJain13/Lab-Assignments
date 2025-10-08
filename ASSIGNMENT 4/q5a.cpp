#include <iostream>
#include <cstring>
using namespace std;

class Queue {
    char* arr;
    int front, rear, MAX;

public:
    Queue(int size) {
        MAX = size;
        arr = new char[MAX];
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

    void enqueue(char ch) {
        if (isFull()) return;
        if (isEmpty()) front = 0;
        arr[++rear] = ch;
    }

    char dequeue() {
        if (isEmpty()) return '\0';
        char x = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return x;
    }

    char getFront() {
        if (isEmpty()) return '\0';
        return arr[front];
    }
};

void firstNonRepeating(string str) {
    int freq[256] = {0};
    Queue q(str.length());

    cout << "Output: ";
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        freq[ch]++;

        q.enqueue(ch);

        while (!q.isEmpty() && freq[q.getFront()] > 1) {
            q.dequeue();
        }

        
        if (q.isEmpty())
            cout << "-1 ";
        else
            cout << q.getFront() << " ";
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter characters: ";
    getline(cin, str);

    string cleaned = "";
    for (char c : str)
        if (c != ' ') cleaned += c;

    firstNonRepeating(cleaned);
    return 0;
}
