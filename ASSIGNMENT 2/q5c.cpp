#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;   
    int *lt = new int[size];     

    cout << "Enter elements row-wise (only lower triangle including diagonal):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int index = (i * (i + 1)) / 2 + j; 
            cin >> lt[index];
        }
    }

    cout << "\nLower Triangular Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                int index = (i * (i + 1)) / 2 + j;
                cout << lt[index] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    delete[] lt; 
    return 0;
}
