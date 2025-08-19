#include <iostream>

using namespace std;


int fill(int n) {

	if (n % 2 == 1)  // 홀수거나 n-2가 0보다 작을 때는 0개
	{
		return 0;
	}
	else if (n == 0)
	{
		return 1;
	}

	else if (n == 2)  // 3*2 일 때는 3 리턴
	{
		return 3;
	}

	else
	{
		int tile = 3 * fill(n - 2);

		for (int i = 4; i <= n; i += 2)
		{
			tile += 2 * fill(n - i);
		}

		return tile;
	}


}

int main() {
	int n;
	cin >> n;

	cout << fill(n) << '\n';

	return 0;
}
