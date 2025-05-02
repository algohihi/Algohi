#include <stdio.h>

int main()
{
    int a, b;

    while (1)
    {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)
            break; // 0 0 입력 시 종료

        if (b % a == 0)
        {
            printf("factor\n");
        }
        else if (a % b == 0)
        {
            printf("multiple\n");
        }
        else
        {
            printf("neither\n");
        }
    }

    return 0;
}