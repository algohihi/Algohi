// Project2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, k, x = 0;
	int i;

	scanf("%d %d", &n, &k); 

	int arr[n]; // 약수 저장할 배열 arr

	for ( i = 1; i <= n; i++)  //1부터 n까지 반복
	{
		if (n % i == 0)  // 약수이면, arr[0]에 저장하고 x+1
		{
			arr[x] = i;
			x++;
		}
	}
	
	if (x < k)  // 약수 개수가 k보다 작으면 0 출력
		printf("0");
	else
		printf("%d \n", arr[k - 1]);

	return 0;
}
