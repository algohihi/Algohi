#include <iostream>

using namespace std;

int n;  // ��¥ �Է�
int t[16], p[16];  // ��� �Ⱓ, �ݾ� �Է�
int summax = 0;

void go(int day, int sum)
{
	if (day > n)  // ����� N�ϱ��� ���� ��
	{
		summax = max(summax, sum);
		return;
	}

	if (day + t[day] <= n + 1)  // ����� �ϴ� ���
	{
		go(day + t[day], sum + p[day]);
	}
	go(day + 1, sum);  // ��� ���ϴ� ���


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
