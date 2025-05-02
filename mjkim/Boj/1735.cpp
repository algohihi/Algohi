// Project2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ac, ap, bc, bp, cc, cp;
	int i, n, min;

	scanf("%d %d", &ac, &ap);
	scanf("%d %d", &bc, &bp);

	cp = ap * bp;
	cc = (ac * bp) + (bc * ap);

	min = (cc < cp) ? cc : cp;

	for ( i = cc; i > 0; i--)
	{
		if (min % i == 0 && cp % i == 0)
		{
			n = i;
			break;
		}
	}
	
	if (n == 1)
		printf("%d %d \n", cc, cp);

	else printf("%d %d \n", cc / n, cp / n);

	return 0;
}