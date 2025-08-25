#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // d[N][K] = 정수 n을 k개의 항으로 만드는 방법 수
    vector<vector<int>> d(n + 1, vector<int>(k + 1, 0));

    // 초기값: 0을 k개 항으로 나타내는 경우는 항상 1가지 (n=0 인 경우는 항상 k의 값을 떠나서 만드는 방법은 1가지)
    for (int j = 0; j <= k; j++) {
        d[0][j] = 1;
    }

    // 점화식: d[n][k] = d[n][k-1] + d[n-1][k]
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            d[i][j] = (d[i][j - 1] + d[i - 1][j]) % 1000000000;
        }
    }

    cout << d[n][k];
    return 0;
}

/*
D[K][N] = ?

O + O + … + O = N
O + O + … + L = N
( N-L ) + L = N 
    N을 만드는 경우의 수 K
    만약 L를 제외하면 (N-L)을 만드는 경우의 수는 K-1(숫자 하나를 제외한 것이므로)

즉,
D[K][N] = D[K-1][N-L] 
L의 범위는 0 <= L <= N
*/
