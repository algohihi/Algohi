#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
    int n, k;                // n: 상어 수, k: 최대 먹을 수 있는 횟수
    long long t;             // t: 상어의 현재 몸집 (long long: 큰 수 대비)
    int arr[200000];         // 상어 크기 배열 (최대 20만 마리)
    
    scanf("%d %d %lld", &n, &k, &t); // n, k, t 입력 받기

    // 상어 크기 입력 받기
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);    // 각 상어의 크기를 배열에 저장
    }

    // k번 반복 (최대 k마리까지 먹을 수 있음)
    for (int i = 0; i < k; i++) 
    {
        int idx = -1;           // 이번에 먹을 상어의 인덱스 (없으면 -1)
        int max = -1;       // 먹을 수 있는 상어 중 가장 큰 값

        // 모든 상어를 확인
        for (int i = 0; i < n; i++) 
        {
            // 아직 먹지 않았고, 몸집 t보다 작은 상어 중에서
            // 가장 큰 상어를 찾음
            if (arr[i] != -1 && arr[i] < t && arr[i] > max) 
            {
                max = arr[i];   // 더 큰 상어 발견
                idx = i;            // 그 상어의 인덱스 저장
            }
        }

        // 먹을 수 있는 상어가 없으면 반복 종료
        if (idx == -1) break;

        t += arr[idx];      // 상어를 먹어서 몸집 키우기
        arr[idx] = -1;      // 먹은 상어는 다시 못 먹게 -1로 표시
    }

    printf("%lld\n", t);    // 최종 몸집 출력
    return 0;               // 프로그램 종료
}
