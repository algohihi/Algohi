#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n = 0; // 상어 마릿수
    int k = 0; // 최대 k마리 먹을 수 있다
    int t = 0; // 샼의 최초 크기
    stack<int> st;  // 상어 크기 정보 스택

    cin >> n >> k >> t;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        st.push(temp);
    }

    // n=5 k=1 t=17
    // 8 9 11 7 6

    int max = 0;
    while (!st.empty()) {
        // 0. st이 비었다면 다 안먹었어도 멈춰야해 (while 조건으로 처리)
        if (st.top() <= t) {
            // 1. 먹을 수 있나? 그럼 max와 비교 max보다 크면 max에 넣고 일단 pop
            if (max < st.top()) max = st.top();
            st.pop();
        } else {
            // 2. 먹을 수 없나? 그럼 max에 있는 값을 더하고 다시 비교
            if (max == 0) {
                // max에 갱신된 값이 없으면 못 먹으므로 break
                break;
            }

            // 하나 먹었으니까 t에 더하고, k-1
            t += max;
            max = 0;
            k--;

            if (k < 0) break; // k 소진
        }
    }

    // 루프가 끝났는데 max가 남아 있다면 아직 먹지 않은 최댓값이 남은 경우임
    if (max != 0) t += max;

    cout << t;
    return 0;
}



/*
stack에 쌓고 top()을 확인해
0. st이 비었다면 다 안먹었어도 멈춰야해
1. 먹을 수 있나? 그럼 max와 비교 max보다 크면 max에 넣고 일단 pop
2. 먹을 수 없나? 그럼 max에 있는 값을 더하고 다시 비교
    - 하나 먹었으니까 k+1
    - 만약에 max에 값이 들어간 적이 없다면? break
*/