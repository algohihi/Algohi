#include <stdio.h>

int main()
{
    int n, k, cnt = 0; // cnt 초기화
    scanf("%d %d", &n, &k);

    int arr[100000] = {0}; // 배열 초기화
    int i;
    // 배열 입력
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            arr[cnt] = i;
            cnt++;
        }
    }

    // k번째 약수 찾기
    if (k <= cnt)
    {
        printf("%d\n", arr[k - 1]);
    }
    else
    {
        printf("0\n");
    }
    return 0;
}