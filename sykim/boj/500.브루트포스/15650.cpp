#include <iostream>
using namespace std;
// 1-N(자연수) > 중복없이 M개 고르기 > 오름차순
// N, M (1 ≤ M ≤ N ≤ 8)
int a[10];
void go(int index, int selected, int n, int m)
{
    if (selected == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << a[i] << ' '; // 수열 출력
        }
        cout << '\n';
        return;
    }

    if (index > n)
        return; // index가 n보다 커지면 종료

    a[selected] = index;               // index를 결과에 추가
    go(index + 1, selected + 1, n, m); // index 증가, selected 증가

    a[selected] = 0;               // index를 결과에 추가 안함
    go(index + 1, selected, n, m); // index 증가, selected 유지
}
int main()
{
    int n, m;
    cin >> n >> m;
    go(1, 0, n, m);
}