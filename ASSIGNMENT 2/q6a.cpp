#include <iostream>
using namespace std;

#define MAX 100

void transpose(int A[][3], int B[][3]) {
    int n = A[0][2]; 

    B[0][0] = A[0][1];  
    B[0][1] = A[0][0];  
    B[0][2] = n;

    int k = 1;

    for (int col = 0; col < A[0][1]; col++) {
        for (int i = 1; i <= n; i++) {
            if (A[i][1] == col) {
                B[k][0] = A[i][1]; 
                B[k][1] = A[i][0]; 
                B[k][2] = A[i][2]; 
                k++;
            }
        }
    }
}

int main() {
    int A[MAX][3], B[MAX][3];
    int rows, cols, nonZero;

    cout << "Enter number of rows, cols, and non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    A[0][0] = rows;
    A[0][1] = cols;
    A[0][2] = nonZero;

    cout << "Enter row, col, value for each non-zero element:\n";
    for (int i = 1; i <= nonZero; i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    transpose(A, B);

    cout << "\nTranspose Matrix in Triplet form:\n";
    for (int i = 0; i <= nonZero; i++) {
        cout << B[i][0] << " " << B[i][1] << " " << B[i][2] << endl;
    }

    return 0;
}
