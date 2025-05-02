// Project2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>;

int main()
{
	int i, len, hlen, cnt = 0;
	char word[100] = { 0 };

	scanf("%s", word);
	len = strlen(word);
	hlen = len / 2;


	for (i = 0; i < hlen; i++)
	{
		if (word[i] == word[len - 1 - i])
			cnt++;
		else break;
	}

	if (cnt == hlen)
	{
		printf("1");
	}
	else printf("0");



	return 0;
}