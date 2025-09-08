#include <iostream>

using namespace std;

bool num[10];  // 해당 수 사용 여부
int a[10];  // m

void go(int index, int n, int m)  // index : 지금 채울 자리
{
	if (index == m)  // 수열 하나 완성
	{
		// 수열 출력
		if (m > 0) 
		{
			cout << a[0];
			for (int i = 1; i < m; i++)
			{
				cout << ' ' << a[i];
			}
			cout << '\n';
		}
	
		return;
	}

	for (int i = 1; i <= n; i++) 
	{
		if (num[i]) continue;  // 이미 뽑아 쓴 숫자 패스

		num[i] = true;   // i 사용 표시

		a[index] = i;  // 현재 자리에 i 넣어주기

		go(index + 1, n, m);  // 다음 인덱스로 넘어감

		num[i] = false;  // 다 쓴 숫자는 다시 false로 바꿔줌
	}
}

int main() 
{
	int n, m;
	cin >> n >> m;

	go(0, n, m);

	return 0;
}