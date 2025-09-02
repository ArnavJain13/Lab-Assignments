#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> s;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            s.push(c - '0'); 
        }
        
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': {
                    int result = 1;
                    for (int j = 0; j < val2; j++) result *= val1;
                    s.push(result);
                    break;
                }
            }
        }
    }
    return s.top();
}

int main() {
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    cout << "Output: " << evaluatePostfix(postfix) << endl;

    return 0;
}
