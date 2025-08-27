#include <iostream>
using namespace std;

int main() {
    char str[100], result[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int i = 0, j = 0;
    while (str[i] != '\0') {
        char c = str[i];

        
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
              c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            result[j] = c; 
            j++;
        }
        i++;
    }
    result[j] = '\0'; 

    cout << "String without vowels: " << result << endl;
    return 0;
}
