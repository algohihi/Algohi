#include <iostream>

using namespace std;

int main()
{
    int n, k;  // 합이 N, 개수 K
    cin >> n >> k;

    int d[201][201] = { 0 };
    d[0][0] = 1;

    for (int i = 1; i <= k; i++) // k개
    {
        for (int j = 0; j <= n; j++) // 합이 n이 되도록
        {
            // 마지막 자리에 오는 수를 l이라고 했을 때 그 앞에 오는 수들의 합은 n-l
            for (int l = 0; l <= j; l++)
            {
                d[i][j] += d[i - 1][j - l];
                d[i][j] %= 1000000000;
            }
        }
    }


    cout << d[k][n] << '\n';

    return 0;
}