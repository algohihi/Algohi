#include <stdio.h>

int main()
{
    int n, m; // N*M 크기의 행렬 설정
    scanf("%d %d", &n, &m);
    int A[100][100] = {0}; // 행렬 초기화
    int B[100][100] = {0}; // 행렬 초기화

    int i, j;
    // 행렬 A 입력
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    // 행렬 B 입력
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &B[i][j]);

    // 행렬 A와 B의 합을 C에 저장
    int C[100][100] = {0}; // 행렬 초기화
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            C[i][j] = A[i][j] + B[i][j];

    // 결과 출력
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}