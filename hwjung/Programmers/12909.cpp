#include <iostream>
#include<stack>
#include<string>
using namespace std;

//C++ 풀이로 변경함에 따라 매개변수 string으로 변경해주어야함
bool solution(string s) {
    
    stack<char> st;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

//범위기반 for문 사용
//일반 for문에 비해 안전하고 간단하지만 index정보가 없다는 단점 존재

