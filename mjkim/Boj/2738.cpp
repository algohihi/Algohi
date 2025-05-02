// Project2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int n, m, i, j;
	int a[100][100], b[100][100], hap[100][100];

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)  // 배열 a 입력 
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < n; i++)  // 배열 b입력
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}

	for (i = 0; i < n; i++)  // 배열 합 구하기
	{
		for (j = 0; j < m; j++)
		{
			hap[i][j] = a[i][j] + b[i][j];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", hap[i][j]);
		}
		printf("\n");
	}
	return 0;
}
