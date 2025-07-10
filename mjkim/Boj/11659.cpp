#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int num[100001] = { 0 };
	int sum[100001] = { 0 };

	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		sum[i] = sum[i - 1] + num[i];

	}


	for (int k = 0; k < m; k++)
	{
		int i, j;
		cin >> i >> j;

		int s;
		s = sum[j] - sum[i - 1];
		cout << s << '\n';
	}
}
