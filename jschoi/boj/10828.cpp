#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    string cmd;
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "push") {
            int temp = 0;
            cin >> temp;
            st.push(temp);
        } else if (cmd == "pop") {
            // C++에 구현된 pop은 스택이 비어있을 때 오류 발생 -> 비어있는지 확인하고 진행
            if (st.empty()) {
                cout << -1 << "\n";
            } else {
                // C++에 구현된 pop은 제거한 요소를 반환하지 않는다 -> top()을 먼저 출력하고 진행
                cout << st.top() << "\n";
                st.pop();
            }
        } else if (cmd == "size") {
            cout << st.size() << "\n";
        } else if (cmd == "empty") {
            cout << st.empty() << "\n"; 
        } else if (cmd == "top") {
            // C++에 구현된 top은 스택이 비어있을 때 오류 발생 -> 비어있는지 확인하고 진행
            if (st.empty()) {
                cout << -1 << "\n"; 
            } else {
                cout << st.top() << "\n";
            }
        }
    }

    return 0;
}
