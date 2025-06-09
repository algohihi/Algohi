// flag없이 바로 return 혹은 함수 반환값
// 실패 시 "NO"를 출력하고, 성공 시 결과를 출력.
#include <stdio.h>
#define MAX_SIZE 100000

typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }
void push(Stack *s, int val) { s->data[++(s->top)] = val; }
int pop(Stack *s) { return s->data[(s->top)--]; }

int main()
{
    int n;             // n: 입력 수열의 길이
    int arr[MAX_SIZE]; // arr: 입력 수열을 저장할 배열
    int idx = 0, num = 1;
    // idx: 현재 비교 중인 수열의 인덱스
    // num: 다음에 push할 숫자(1부터 n까지)
    char result[MAX_SIZE * 2]; // +, - 연산을 저장할 배열 (최대 2n개)
    int res_idx = 0;           // result 배열의 현재 인덱스

    scanf("%d", &n); // 수열의 길이 입력
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]); // 수열 입력

    Stack s;
    init(&s); // 스택 선언 및 초기화

    // 수열의 모든 숫자를 처리할 때까지 반복
    while (idx < n)
    {
        // 1. 스택이 비었거나, 스택 top이 arr[idx]보다 작고, push할 숫자가 n 이하면 push
        if ((s.top == -1 || s.data[s.top] < arr[idx]) && num <= n)
        {
            push(&s, num++);
            result[res_idx++] = '+';

        } // 2. 스택 top이 arr[idx]와 같으면 pop
        else if (s.data[s.top] == arr[idx])
        {
            pop(&s);
            result[res_idx++] = '-';
            idx++;
        } // 3. 그 외의 경우(수열을 만들 수 없음)
        else
        {
            printf("NO\n"); // 실패 시 "NO" 출력
            return 0;       // 프로그램 종료
        }
    }

    // 가능하면 저장된 연산 결과를 한 줄씩 출력
    for (int i = 0; i < res_idx; i++)
        printf("%c\n", result[i]);
    return 0;
}
