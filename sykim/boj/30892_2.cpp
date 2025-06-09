
// 퀵소트(Quick sort) > 정답처리
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 200000
long long n, k, t;
long long scale[MAX_NUM + 1];

typedef struct
{
    long long data[MAX_NUM];
    long long top;
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

long long is_empty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, long long c)
{
    s->data[++s->top] = c;
}

long long pop(Stack *s)
{
    if (is_empty(s))
        return 0;
    return s->data[s->top--];
}

// 퀵소트를 위한 비교 함수
// 현재는 오름차순임
// 내림차순으로 할 거면 > return 1과-1을 바꾸면 됨
int compare(const void *a, const void *b)
{
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    if (x < y)
        return -1; //(음수취급) X가 Y보다 작으면 앞으로 보냄
    if (x > y)
        return 1; //(양수) X가 Y보다 크면 뒤로 보냄
    return 0;
}

int main()
{
    // n: 바다에 있는 상어 마릿수
    // k: 먹을 수 있는 최대 마릿수
    // t: 샼의 최초 크기
    scanf("%lld %lld %lld", &n, &k, &t);

    for (int i = 0; i < n; i++)
    { // scale : 앞바다에 있는 상어 크기
        scanf("%lld", &scale[i]);
    }

    // ⚡ 핵심: O(n²) → O(n log n) 정렬로 변경
    qsort(scale, n, sizeof(long long), compare);

    Stack sea;
    init(&sea);

    int i = 0;
    while (k > 0 && i < n)
    {
        // 현재 샼보다 작은 상어들을 스택에 push
        while (i < n && t > scale[i])
        {
            push(&sea, scale[i]);
            i++;
        }

        // 스택에서 가장 큰 상어부터 먹기
        if (!is_empty(&sea))
        {
            long long eaten = pop(&sea);
            t += eaten;
            k--;
        }
        else
        {
            break;
        }
    }

    // 남은 k가 있고 스택에 상어가 있으면 계속 먹기
    while (k > 0 && !is_empty(&sea))
    {
        long long eaten = pop(&sea);
        t += eaten;
        k--;
    }

    printf("%lld\n", t);
    return 0;
}

/*
#include <string.h> // memcpy, memmove 사용 // 8바이트 (64비트)
#include <stdlib.h> // malloc, free 사용
//(배열이름, 요소개수, 요소크기, 비교함수이름)
void qsort(long long *scale, size_t n, size_t size, int (*compare)(const void *, const void *)) {
    if (n < 2) return;

    char *arr = (char *)scale;
    char *pivot = arr; // 첫 번째 원소를 피벗으로 사용
    size_t i, j = 0;

    // 임시 버퍼
    char *tmp = (char *)malloc(size);

    // 파티션: 피벗보다 작은 값들을 앞으로 이동
    for (i = 1; i < n; ++i) {
        if (compare(arr + i * size, pivot) < 0) {
            ++j;
            memcpy(tmp, arr + i * size, size);
            memmove(arr + size, arr, j * size);
            memcpy(arr, tmp, size);
        }
    }
    free(tmp);

    // 재귀적으로 좌우 부분 정렬
    qsort((long long *)arr, j, size, compare);
    qsort((long long *)(arr + (j + 1) * size), n - j - 1, size, compare);
}



memcpy(tmp, arr + i * size, size);
→ 현재 비교 중인 원소(arr + i * size)를 임시 버퍼(tmp)에 복사합니다.
즉, 이동시킬 값을 임시로 저장합니다.

memmove(arr + size, arr, j * size);
→ 배열의 앞쪽(j개) 데이터를 한 칸 뒤로 밀어줍니다.
즉, 피벗보다 작은 값을 앞으로 넣기 위해 공간을 만듭니다.

memcpy(arr, tmp, size);
→ 임시 버퍼에 있던 값을 배열의 맨 앞(피벗 자리)에 복사합니다.
즉, 피벗보다 작은 값을 배열의 앞부분(피벗 자리)에 위치시킵니다.




"""
함수별 공식 설명
memcpy

메모리의 특정 구간을 다른 구간으로 정확히 지정한 바이트 수만큼 복사합니다.

두 메모리 영역이 겹치면 안 됩니다.

예: memcpy(dest, src, size); → src에서 size만큼 dest로 복사

memmove

memcpy와 거의 같지만, 메모리 영역이 겹쳐도 안전하게 복사합니다.

내부적으로 임시 버퍼를 사용해 원본 데이터 손실 없이 복사합니다.

예: memmove(dest, src, size); → src에서 size만큼 dest로 복사(겹쳐도 안전)
"""
*/