#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix (n x n): ";
    cin >> n;

    int size = 3 * n - 2;
    int tri[size];

    cout << "Enter tri-diagonal elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> tri[i];
    }

    cout << "Tri-diagonal Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {               
                cout << tri[k++] << " ";
            } 
            else if (i == j + 1) {      
                cout << tri[k++] << " ";
            } 
            else if (i + 1 == j) {      
                cout << tri[k++] << " ";
            } 
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return 0;
}
