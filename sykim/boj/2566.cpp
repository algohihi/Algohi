#include <stdio.h>

int main()
{
    int arr[9][9] = {0}; // 9x9 행렬 초기화
    int i, j;
    // 행렬 입력
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            scanf("%d", &arr[i][j]);

    int max = 0;              // 최대값 초기화
    int max_i = 0, max_j = 0; // 최대값의 위치 초기화
    // 최대값 찾기
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                max_i = i;
                max_j = j;
            }
    // 결과 출력
    printf("%d\n", max);
    printf("%d %d\n", max_i + 1, max_j + 1); // 1-based index로 출력

    return 0;
}