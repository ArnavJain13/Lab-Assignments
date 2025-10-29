#include <iostream> 
using namespace std;

int arr[100];
int n = 0;

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement() {
    int pos, val;
    if (n == 100) {
        cout << "Array full!\n";
        return;
    }
    cout << "Enter position (1-" << n+1 << "): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;
    if (pos < 1 || pos > n+1) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos-1] = val;
    n++;
}

void deleteElement() {
    int pos;
    if (n == 0) {
        cout << "Array empty!\n";
        return;
    }
    cout << "Enter position (1-" << n << "): ";
    cin >> pos;
    if (pos < 1 || pos > n) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = pos-1; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
}

void linearSearch() {
    int val;
    bool found = false;
    cout << "Enter value to search: ";
    cin >> val;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            cout << "Found at position " << i+1 << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Not found.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
