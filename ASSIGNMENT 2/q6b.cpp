#include <iostream>
using namespace std;

#define MAX 100

void addSparse(int A[][3], int B[][3], int C[][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Matrices dimensions do not match. Cannot add!\n";
        return;
    }

    int nA = A[0][2], nB = B[0][2];
    int i = 1, j = 1, k = 1;

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= nA && j <= nB) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++;
        }
        else if (B[j][0] < A[i][0] || (A[i][0] == B[j][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++;
        }
        else { 
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
            } else {
                k--; 
            }
            i++; j++;
        }
        k++;
    }

    while (i <= nA) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= nB) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1; 
}

int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3];
    int rows, cols, nA, nB;

    cout << "Enter rows and cols of matrices: ";
    cin >> rows >> cols;

    cout << "Enter number of non-zero elements in Matrix A: ";
    cin >> nA;
    A[0][0] = rows; A[0][1] = cols; A[0][2] = nA;
    cout << "Enter row, col, value for Matrix A:\n";
    for (int i = 1; i <= nA; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter number of non-zero elements in Matrix B: ";
    cin >> nB;
    B[0][0] = rows; B[0][1] = cols; B[0][2] = nB;
    cout << "Enter row, col, value for Matrix B:\n";
    for (int i = 1; i <= nB; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    addSparse(A, B, C);
    
    cout << "\nResultant Matrix in Triplet form:\n";
    for (int i = 0; i <= C[0][2]; i++) {
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;
    }

    return 0;
}
