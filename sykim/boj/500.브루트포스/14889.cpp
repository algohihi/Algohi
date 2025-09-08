#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int s[20][20]; // 능력치 배열 > 4 <= N <= 20

int main()
{
    int n; // N값 입력받기
    cin >> n;
    for (int i = 0; i < n; i++) // 스타트팀 능력치 입력받기
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }

    int answer = -1; // 능력치 차이의 최솟값을 저장할 변수

    for (int i = 0; i < (1 << n); i++)
    {                            // 2^n가지의 부분집합에 대해 확인
        vector<int> start, link; // 스타트팀과 링크팀을 저장할 벡터
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                start.push_back(j); // j번째 비트가 1이면 스타트팀에 추가
            else
                link.push_back(j); // j번째 비트가 0이면 링크팀에 추가
        }
        if (start.size() != n / 2)
            continue; // 스타트팀과 링크팀의 크기가 같지 않으면 건너뜀

        int start_sum = 0, link_sum = 0; // 각 팀의 능력치 합을 저장할 변수

        for (int l1 = 0; l1 < start.size(); l1++)
        { // 스타트팀과 링크팀의 능력치 합 계산
            for (int l2 = l1 + 1; l2 < start.size(); l2++)
            {
                start_sum += s[start[l1]][start[l2]] + s[start[l2]][start[l1]]; // 스타트팀 능력치 합 계산
                link_sum += s[link[l1]][link[l2]] + s[link[l2]][link[l1]];      // 링크팀 능력치 합 계산
            }
        }
        int diff = abs(start_sum - link_sum); // 능력치 차이 계산 ->  ads : 절댓값 함수
        if (answer == -1 || diff < answer)
            answer = diff; // 최솟값 갱신
    }
    cout << answer << '\n'; // 능력치 차이의 최솟값 출력

    return 0;
}