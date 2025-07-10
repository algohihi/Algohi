#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    // presum은 배열의 1~i의 합
    vector<int> sum(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }

    // 구간 합 출력
    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        cout << sum[end] - sum[start - 1] << "\n";
    }

    return 0;
}