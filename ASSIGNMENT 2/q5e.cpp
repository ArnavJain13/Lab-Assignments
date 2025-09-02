#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;  
    int sym[size];

    cout << "Enter elements row-wise (lower triangular part including diagonal):\n";
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {  
            cin >> sym[index++];
        }
    }

    cout << "Symmetric Matrix:\n";
    index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {   
                cout << sym[(i * (i + 1)) / 2 + j] << " ";
            } else {        
                cout << sym[(j * (j + 1)) / 2 + i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
