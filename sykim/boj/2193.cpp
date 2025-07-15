#include <iostream>
using namespace std;
#define N_MAX 90

// 0 자동 초기화
// cnt[1] - cnt[91]
long long cnt[N_MAX + 1] = {0, 1, 1};

int main()
{
    int n;

    // scanf("%d", &n);
    cin >> n;

    if (n <= 0 || n > N_MAX)
        return 0;

    for (int i = 3; i <= n; i++)
    {
        cnt[i] = cnt[i - 1] + cnt[i - 2];
    }

    cout << cnt[n];

    return 0;
}