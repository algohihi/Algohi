#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int height[9];
	int sum = 0;

	// 난쟁이들 키 입력
	for (int i = 0; i < 9; i++)
	{
		cin >> height[i];
		sum += height[i];  // 키를 모두 sum에 합해서 저장
	}

	sort(height, height + 9);  // 오름차순 정렬

	// 9명 중에 7명 선택
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++) {

			// 9명 중에서 2명 뺀 값이 100이면
			if (sum - height[i] - height[j] == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					// 그 두명 빼고 출력
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