#include <iostream>

using namespace std;

int n;  // 날짜 입력
int t[16], p[16];  // 상담 기간, 금액 입력
int summax = 0;

void go(int day, int sum)
{
	if (day > n)  // 상담을 N일까지 했을 때
	{
		summax = max(summax, sum);
		return;
	}

	if (day + t[day] <= n + 1)  // 상담을 하는 경우
	{
		go(day + t[day], sum + p[day]);
	}
	go(day + 1, sum);  // 상담 안하는 경우


}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}

	go(1, 0);

	cout << summax << '\n';

	return 0;
}
