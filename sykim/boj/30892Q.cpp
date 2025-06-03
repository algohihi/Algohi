
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
int compare(const void *a, const void *b)
{
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

int main()
{
    scanf("%lld %lld %lld", &n, &k, &t);

    for (int i = 0; i < n; i++)
    {
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
