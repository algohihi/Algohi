
#include <iostream> // 표준입출력 사용
#include <deque>    // 덱 자료구조 사용
using namespace std;

int main()
{
    int n, m;      // n : 큐 크기, m : 뽑을 개수
    int count = 0; // count : 연산 횟수 누적

    cin >> n >> m; // 입력 받기

    deque<int> dq; // 덱 선언

    for (int i = 1; i <= n; i++)
    {
        // 1~n까지 숫자를 덱에 넣음
        dq.push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        // m개의 숫자를 차례로 뽑음
        int x;
        cin >> x; // 뽑을 숫자 입력

        int idx = 0; // x가 덱에서 몇 번째 있는지 찾기 위한 인덱스 변수
        while (dq[idx] != x)
            idx++; // x가 나올 때 까지 idx 증가

        // x가 덱의 앞쪽에 더 가까우면(왼쪽회전이 더 적으면)
        if (idx <= (dq.size() / 2))
        { //(뽑으려는 수 <= 덱 원소 개수 절반)
            // x가 맨 앞으로 올 때까지 왼쪽으로 한 칸씩 이동
            while (dq.front() != x)
            {
                dq.push_back(dq.front()); // 맨 앞 원소 > 뒤로 보냄
                dq.pop_back();            // 맨 뒤 원소 제거
                count++;                  // 연산 횟수 증가
            }
        }
        else
        { // x가 덱 뒤쪽과 더 가까우면(오른쪽 회전 더 적으면)
            // x가 맨 앞에 올 때까지 오른쪽으로 한 칸씩 이동
            while (dq.front() != x)
            {
                dq.push_front(dq.back()); // 맨 뒤 원소 > 앞으로 보냄
                dq.pop_back();            // 맨 뒤 원소 제거
                count;                    // 연산 횟수 증가
            }
        }

        dq.pop_front(); // x가 맨 앞에 오면 꺼냄
    }
    cout << count << endl;
}
