#include <iostream>

using namespace std;

bool num[10];  // �ش� �� ��� ����
int a[10];  // m

void go(int index, int n, int m)  // index : ���� ä�� �ڸ�
{
	if (index == m)  // ���� �ϳ� �ϼ�
	{
		// ���� ���
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
		if (num[i]) continue;  // �̹� �̾� �� ���� �н�

		num[i] = true;   // i ��� ǥ��

		a[index] = i;  // ���� �ڸ��� i �־��ֱ�

		go(index + 1, n, m);  // ���� �ε����� �Ѿ

		num[i] = false;  // �� �� ���ڴ� �ٽ� false�� �ٲ���
	}
}

int main() 
{
	int n, m;
	cin >> n >> m;

	go(0, n, m);

	return 0;
}