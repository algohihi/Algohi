#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int height[9];
	int sum = 0;

	// �����̵� Ű �Է�
	for (int i = 0; i < 9; i++)
	{
		cin >> height[i];
		sum += height[i];  // Ű�� ��� sum�� ���ؼ� ����
	}

	sort(height, height + 9);  // �������� ����

	// 9�� �߿� 7�� ����
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++) {

			// 9�� �߿��� 2�� �� ���� 100�̸�
			if (sum - height[i] - height[j] == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					// �� �θ� ���� ���
					if (k == i || k == j)
					{
						continue;
					}

					cout << height[k] << '\n';
				}
				return 0;
			}
		}
	}
	return 0;
}