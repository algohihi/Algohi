#include <iostream>
using namespace std;

// 1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.
// 1234567891011121314151617181920212223...
// 이렇게 만들어진 새로운 수는 몇 자리 수일까? 이 수의 자릿수를 구하는 프로그램을 작성하시오.
// 첫째 줄에 N(1 ≤ N ≤ 100,000,000)이 주어진다. > (1- 9자릿수)
// 첫째 줄에 새로운 수의 자릿수를 출력한다.

int main()
{
    int n;
    cin >> n; // 120

    long long answer = 0; // 자릿수 출력

    for (int start = 1, len = 1; start <= n; start *= 10, len++) // start = 1 부터 시작, len 길이 = 1 부터 시작  > 1- 120까지 나열 > 10씩 증가 / 길이는 1씩 증가
    {
        int end = start * 10 - 1; // 10-1(9) > 100-1(99) > 1000-1(999)...
        if (end > n)              // (99 > 120) ->  (999 > 120) x
        {
            end = n; // end = 120
        }
        answer += (long long)(end - start + 1) * len; // answer = answer + (9-1+1)*1 > ans = ans + (99-10+1)*2 > ans = ans + (120-100+1)*3 ...
    }
    cout << answer << '\n';

    return 0;
}