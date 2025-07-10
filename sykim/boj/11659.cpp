#include <iostream>
using namespace std;

#define N_MAX 100000 // (1 <= N <= 100,000)
#define M_MAX 100000 // (1 <= M <= 100,000)

// 전역변수 배열선언시 자동 '0' 초기화
int arr[N_MAX + 1];     // N개 배열 받기 > 1부터 사용 > (+1)
int eachSum[M_MAX + 1]; // 배열 순서별 > 각 합 저장해 놓기 > 1부터 사용 > (+1)
int finSum[M_MAX];      // i-j까지 최종 결과합 저장 > 0부터 사용

int main()
{
    int n = 0, m = 0;
    int i = 0, j = 0;

    cin >> n >> m; // 5, 3

    for (i = 1; i <= n; i++)
    { // 5,4,3,2,1

        cin >> arr[i]; // arr[1] - arr[5] 배열값 받기

        eachSum[i] = eachSum[i - 1] + arr[i]; // eachSum[1] = eachSum[0] + arr[1] = 5 ...
    }

    for (int k = 0; k < m; k++) // (i-j)각 구간 합 배열에 저장  > 0(k) - 3(m) > (0,1,2)
    {
        cin >> i >> j; // 구간 [i, j] 입력 // (1, 3) > (2, 5) > (5, 5)

        finSum[k] = eachSum[j] - eachSum[i - 1]; // eachSum[3] - eachSum[3-1]
    }

    for (int k = 0; k < m; k++)
    { // 0,1,2 결과 출력

        cout << finSum[k] << '\n';
    }

    return 0;
}
