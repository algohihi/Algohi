#include <iostream>

using namespace std;

int main()
{
	int e, s, m;
	cin >> e >> s >> m;  // 입력받아서

	// 나머지가 0일 때를 예외 처리
	e -= 1;
	s -= 1;
	m -= 1;

	// 해당 년도를 각 행성의 값으로 나눴을 때의 나머지가 입력받은 값이므로 
	for (int i = 0; ; i++)
	{
		if (i % 15 == e && i % 28 == s && i % 19 == m)
		{
			cout << i + 1 << '\n';
			break;
		}
	}
	return 0;
}