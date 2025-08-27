#include <iostream>
using namespace std;

int compareStrings(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];  
        }
        i++;
    }
    return s1[i] - s2[i];
}

void copyString(char s1[], char s2[]) {
    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void sortStrings(char arr[][50], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (compareStrings(arr[i], arr[j]) > 0) {
                char temp[50];
                copyString(temp, arr[i]);
                copyString(arr[i], arr[j]);
                copyString(arr[j], temp);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    char arr[20][50];
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sortStrings(arr, n);

    cout << "\nStrings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
