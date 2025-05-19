#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// c언어랑 다르게 참조타입 매개변수일 때 함수 선언, 호출할 때 키워드 다 안써도 됨
// cpp에서는 선언할때 & 참조타입으로 받게하고, 호출할때는 변수명만 넣으면 알아서 참조타입 전달

void solution(const string& testcase) {
    stack<char> stl; // 왼쪽
    stack<char> str; // 오른쪽

    for (char ch : testcase) {
        switch (ch) {
            case '<':
                if (!stl.empty()) {
                    str.push(stl.top());
                    stl.pop();
                }
                break;
            case '>':
                if (!str.empty()) {
                    stl.push(str.top());
                    str.pop();
                }
                break;
            case '-':
                if (!stl.empty()) {
                    stl.pop();
                }
                break;
            default:
                stl.push(ch);
        }
    }

    // 왼쪽 스택을 벡터로 옮겨서 역순 출력
    vector<char> left;
    while (!stl.empty()) {
        left.push_back(stl.top());
        stl.pop();
    }

    // v.rbegin() : 벡터의 마지막 요소부터 시작하는 역방향 반복자
    // v.rend() : 벡터의 첫 번째 요소 앞을 가리키는 역방향 반복자
    for (auto it = left.rbegin(); it != left.rend(); ++it) {
        cout << *it;
    }

    // 오른쪽 스택은 top부터 바로 출력 (역순이 아님)
    while (!str.empty()) {
        cout << str.top();
        str.pop();
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int caseCnt;
    cin >> caseCnt;
    while (caseCnt--) {
        string testcase;
        cin >> testcase;
        solution(testcase);
    }
    return 0;
}



/*
cursor를 기준으로 left, right stack을 만든다
cusor위치 변화가 없는 경우 stl push한다

1. < 인 경우 str.push(stl.top()); stl.pop();
2. > 인 경우 stl.push(stl.top()); str.pop();
3. - 인 경우 stl.pop();
    * 1,2,3을 실행하기 전에 반드시 isempty()를 체크한다
4. 1,2,3에 해당하지 않는 경우 stl.push()한다
*/