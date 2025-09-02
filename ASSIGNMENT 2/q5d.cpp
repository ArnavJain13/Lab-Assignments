#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;  
    int upper[size];

    cout << "Enter elements row-wise (only upper triangle including diagonal):\n";
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {   
            cin >> upper[index++];
        }
    }

    cout << "Upper Triangular Matrix:\n";
    index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i)  
                cout << upper[index++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}
