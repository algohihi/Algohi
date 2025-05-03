// Project2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    int n, num;
    int str[50];

    while (scanf("%d", &n) != EOF)  // EOF까지 계속 반복
    {
        for (int i = 0; i < n; i++)  // n개의 약수 입력
        {
            scanf("%d", &str[i]);
        }
		if (n == 1)  //약수 1개면 제곱
		{
			num = pow(str[0], 2);
		}
		else if (n > 1)  // 약수 1개 이상이면
		{
			int i, j, tmp;
			for (i = 0; i < n - 1; i++)  // 오름차순 정렬
			{
				for (j = 1 + i; j < n; j++)
				{
					if (str[i] > str[j])
					{
						tmp = str[i];
						str[i] = str[j];
						str[j] = tmp;
					}
				}
			}
			num = str[0] * str[n - 1];  // 제일 작은 수 * 제일 큰 수 
		}
		printf("%d", num);
	}

	return 0;
}
