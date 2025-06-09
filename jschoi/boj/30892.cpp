#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n = 0; // 상어 마릿수
    int k = 0; // 최대 k마리 먹을 수 있다
    long long t = 0; // 샼의 최초 크기
    vector<long long> sharks; // 상어 담을 Vector

    // 입력받고 정렬
    cin >> n >> k >> t;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        sharks.push_back(s);
    }
    sort(sharks.begin(), sharks.end());

    // 먹어보자
    int i = 0; // 이미 추가한 상어는 추가 안하려고 밖에서 선언
    stack<long long> st;
    while(k > 0){
        // 먹을 수 있는 상어 스택에 추가하기
        while(i < n && sharks[i] < t) st.push(sharks[i++]);

        // 먹을 수 있는 상어가 없으면 break
        if(st.empty()) break;
        
        // 먹을 수 있는 상어가 있으면
        t += st.top();
        st.pop();
        k -= 1;
    }

    cout << t;
    return 0;
}