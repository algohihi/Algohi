// Project2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
	int max = 0, i, j;
	int row = 0, column = 0;
	int arr[9][9];

	
	for ( i = 0; i < 9; i++) // 배열 입력
	{
		for ( j = 0; j < 9; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	
	for (i = 0; i < 9; i++)   // 최대값 찾기 & 배열 위치 저장
	{
		for (j = 0; j < 9; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
				row = i;  
				column = j;
			}
		}
	}

	printf("%d \n", max);
	printf("%d %d \n", row+1, column+1);

	return 0;
}

