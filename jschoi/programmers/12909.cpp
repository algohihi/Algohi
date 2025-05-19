#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solution(const string& s) {
    stack<char> st;

    if (s[0] == ')') return false;

    for (char ch : s) {
        if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            if (st.empty()) return false;
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string input;
    cin >> input;

    if (solution(input)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}
