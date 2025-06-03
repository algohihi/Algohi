//시간 초과 // 버블정렬

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 200000
long long n, k, t;
long long scale[MAX_NUM+1];

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

long long is_full(Stack *s)
{
    return s->top == MAX_NUM - 1;
}

void push(Stack *s, long long c)
{
    if (is_full(s)) return;
    s->data[++s->top] = c;
}

long long pop(Stack *s)
{
    if (is_empty(s)) return 0;
    return s->data[s->top--];
}

int main() {
    scanf("%lld %lld %lld", &n, &k, &t);
    
    // 입력 수정
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &scale[i]);
    }

    // 오름차순 정렬 (데이터 타입 수정)
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = i+1; j < n; j++)
        {
            long long tmp = 0;  // long long으로 수정
            if (scale[i] > scale[j])
            {
                tmp = scale[i];
                scale[i] = scale[j];
                scale[j] = tmp;
            }
        }
    }
    
    Stack sea;
    init(&sea);
    
    int i = 0; //// 현재 확인 중인 상어 인덱스
    while (k > 0 && i < n) 
    {//샼이 먹을 수 있는 마리수(k)가 남아 있고,확인할 상어(i)가 남아 있을 때만 반복
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
            // 더 이상 먹을 수 있는 상어가 없으면 종료
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