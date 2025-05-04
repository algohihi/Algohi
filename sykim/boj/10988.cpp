#include <stdio.h>
#include <string.h>

int main()
{
    char word[100];
    int len = 0;

    scanf("%s", word);
    len = strlen(word);
    int len_half = len / 2;
    int result = 1; // 초기에 회문(팰린드롬)이라고 가정

    for (int i = 0; i < len_half; i++)
    {
        if (word[i] != word[(len - i) - 1]) // 대칭이 맞지 않으면
        {
            result = 0; // 회문(팰린드롬)이 아님
            break;      // 더 이상 검사할 필요 없음
        }
    }

    printf("%d\n", result);
    return 0;
}