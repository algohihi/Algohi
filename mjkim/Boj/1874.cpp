#include <stdio.h>
#define MAX 100001  // 수열 최대 길이 + 여유 공간

int stack[MAX];        // 스택으로 사용할 배열
int top = -1;          // 스택 top 위치

// 스택에 숫자 push + 연산 기록
void push(int x)
{
    stack[++top] = x;     // 스택에 숫자 추가

}

// 스택에서 숫자 pop + 연산 기록
int pop()
{
    return stack[top--];    
}

int main()
{
    int n, arr[MAX];        // n: 수열 길이, arr[]: 입력 수열

    scanf("%d", &n);        // 수열 길이 입력

    // 수열 입력 받기 (0번 인덱스부터 사용)
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int num = 1;  // 현재 push할 숫자 (1부터 시작)
    int idx = 0;  // 현재 비교 중인 수열 인덱스

    // 수열 전체 처리할 때까지 반복
    while (idx < n)
    {
        // 스택이 비었거나, 스택 top이 arr[idx]보다 작으면 push
        if ((top == -1 || stack[top] < arr[idx]) && num <= n)
        {
            push(num++);  // 숫자 push하고 다음 숫자 준비
            printf("+\n");
        }
        // 스택 top이 arr[idx]와 같으면 pop
        else if (stack[top] == arr[idx])
        {
            pop();    // 목표 숫자 pop
            printf("-\n");
            idx++;    // 다음 수열로 이동
        }
        // 스택 top이 목표보다 크면 수열 생성 불가
        else
        {
            printf("NO\n");
            return 0;  // 실패하고 종료
        }
    }

    return 0;
}






// 출력초과래여
// 출력을 배열에 기록했다가 출력하면 되는건가

#include <stdio.h>
#define MAX 100001  // 수열 최대 길이 + 여유 공간

int stack[MAX];        // 스택으로 사용할 배열
int top = -1;          // 스택 top 위치

char output[MAX * 2];  // 출력 기록
int outidx = 0;       // 출력 배열 인덱스


// 스택에 숫자 push + 연산 기록
void push(int x)
{
    stack[++top] = x;     // 스택에 숫자 추가
    output[outidx++] = '+';

}

// 스택에서 숫자 pop + 연산 기록
int pop()
{
    output[outidx++] = '-';
    return stack[top--];
}

int main()
{
    int n, arr[MAX];        // n: 수열 길이, arr[]: 입력 수열

    scanf("%d", &n);        // 수열 길이 입력

    // 수열 입력 받기 (0번 인덱스부터 사용)
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int num = 1;  // 현재 push할 숫자 (1부터 시작)
    int idx = 0;  // 현재 비교 중인 수열 인덱스

    // 수열 전체 처리할 때까지 반복
    while (idx < n)
    {
        // 스택이 비었거나, 스택 top이 arr[idx]보다 작으면 push
        if ((top == -1 || stack[top] < arr[idx]) && num <= n)
        {
            push(num++);  // 숫자 push하고 다음 숫자 준비
        }
        // 스택 top이 arr[idx]와 같으면 pop
        else if (stack[top] == arr[idx])
        {
            pop();    // 목표 숫자 pop
            idx++;    // 다음 수열로 이동
        }
        // 스택 top이 목표보다 크면 수열 생성 불가
        else
        {
            printf("NO\n");
            return 0;  // 실패하고 종료
        }
    }

    // 연산 결과 출력 (+, -)
    for (int i = 0; i < outidx; i++) {
        printf("%c \n", output[i]);
    }

    return 0;
}




