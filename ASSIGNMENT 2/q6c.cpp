#include <iostream>
using namespace std;

#define MAX 100

void multiplySparse(int A[][3], int B[][3], int C[][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Matrix dimensions do not allow multiplication!\n";
        return;
    }

    int rows = A[0][0], cols = B[0][1];
    int nA = A[0][2], nB = B[0][2];
    int k = 1;

    C[0][0] = rows;
    C[0][1] = cols;

    for (int i = 1; i <= nA; i++) {
        for (int j = 1; j <= nB; j++) {
            
            if (A[i][1] == B[j][0]) {
                int r = A[i][0];
                int c = B[j][1];
                int val = A[i][2] * B[j][2];

                bool found = false;
                for (int x = 1; x < k; x++) {
                    if (C[x][0] == r && C[x][1] == c) {
                        C[x][2] += val;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    C[k][0] = r;
                    C[k][1] = c;
                    C[k][2] = val;
                    k++;
                }
            }
        }
    }

    C[0][2] = k - 1;
}

int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3];
    int r1, c1, r2, c2, nA, nB;

    cout << "Enter rows and cols of Matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter number of non-zero elements in Matrix A: ";
    cin >> nA;
    A[0][0] = r1; A[0][1] = c1; A[0][2] = nA;
    cout << "Enter row col value for Matrix A:\n";
    for (int i = 1; i <= nA; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter rows and cols of Matrix B: ";
    cin >> r2 >> c2;
    cout << "Enter number of non-zero elements in Matrix B: ";
    cin >> nB;
    B[0][0] = r2; B[0][1] = c2; B[0][2] = nB;
    cout << "Enter row col value for Matrix B:\n";
    for (int i = 1; i <= nB; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    multiplySparse(A, B, C);

    cout << "\nResultant Matrix in Triplet form:\n";
    for (int i = 0; i <= C[0][2]; i++) {
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;
    }

    return 0;
}