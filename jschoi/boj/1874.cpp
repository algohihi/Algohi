#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> arr;
    stack<int> st;
    cin >> n;

    // 순서 입력 받기
    for(int i = 0; i < n; i++){
        int temp = 0;
        cin >> temp;
        arr.push_back(temp);
    }

    // 확인 시작
    int idx = 0;
    string res = "";
    for(int i = 1; i <= n; i++){
        st.push(i);
        res += "+\n";
        while(!st.empty() && arr[idx] == st.top()){
            st.pop();
            res += "-\n";
            idx += 1;
        }
    }

    if(st.empty()){
        cout << res;
    }else{
        cout << "NO";
    }
    return 0;
}


/*
n까지 숫자 다 push 했을 때  -> stack.empty() = f 확인

1. n을 입력받는다
2. 입력받은 수를 arr에 넣는다 (43687521)
3. arr를 순회할 변수 하나를 선언한다(idx)
4. for문 돌린다.. (1~n까지)
    1. arr[idx] 와 같은 값이 나올 때 까지 push ( + 출력)
    2. 같은 값이 나오면 pop ( - 출력)
5. for문 빠져 나왔을 때 stack.empty() = f 확인
    1. 안비어있으면 NO
*/