
#include <stdio.h>
#include <stdlib.h> //난수생성, 문자열 형식을 다른 형식으로 변환, 의사 난수 생성, 동적 메모리 관리 등의 함수를 포함
#include <string.h> //문자열 처리 함수

int stack[10000];
char word[10000];

int n = 0;

int main()
{
    int top = 0;
    scanf("%d", &n); // 14
    for (int i = 0; i < n; i++)
    {
        scanf("%s", word);
        if (strcmp(word, "push") == 0) // work[0] = push
        {
            int x;
            top++;
            if (top > n)
            {
                printf("overflow");
                return 0;
            }
            scanf("%d", &x);
            stack[top] = x;
        }
        else if (strcmp(word, "pop") == 0)
        {
            if (top == 0)
                printf("-1\n");
            else
            {
                printf("%d\n", stack[top]);
                top--;
            }
        }
        else if (strcmp(word, "size") == 0)
        {
            printf("%d\n", top);
        }
        else if (strcmp(word, "empty") == 0)
        {
            printf("%d\n", top == 0 ? 1 : 0);
        }
        else if (strcmp(word, "top") == 0)
        {
            if (top == 0)
                printf("-1\n");
            else
                printf("%d\n", stack[top]);
        }
    }

    return 0;
}
