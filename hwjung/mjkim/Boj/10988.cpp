// Project2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>;

int main()
{
	int i, len, hlen, cnt = 0;
	char word[100] = { 0 };

	scanf("%s", word);  //문자 입력
	len = strlen(word);  // 문자 길이
	hlen = len / 2;  // 반띵


	for (i = 0; i < hlen; i++)  // 반띵까지 반복
	{
		if (word[i] == word[len - 1 - i]) // 첫글자 마지막 글자 일치할 경우 cnt++
			cnt++;
		else break;
	}

	if (cnt == hlen) // 횟수랑 반띵이랑 잋피하면 팰린드롬
	{
		printf("1");
	}
	else printf("0");



	return 0;
}




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int i, len;
    char word[100] = { 0 };

    scanf("%s", word);
    len = strlen(word);

    for (i = 0; i < len / 2; i++) {
        if (word[i] != word[len - 1 - i]) {
            printf("0");
            return 0; // 팰린드롬 아님, 종료
        }
    }

    printf("1"); // 끝까지 다 같으면 팰린드롬
    return 0;
}
