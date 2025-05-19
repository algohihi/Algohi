#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000000
/*
InitStack : 빈 스택 만들기
IsFull : 스택이 꽉 찼는지 확인
IsEmpty : 스택이 비어있는지 확인
Peek : 꼭대기의 요소를 읽음
Push : 꼭대기에 요소 삽입
Pop : 꼭대기의 요소 제거
*/

typedef struct
{
    char data[MAX_LEN];
    int top;
} Stack;

void init(Stack *s)
{ // 처음 비어있는 스택 만들기// 초기상태로 되돌리는 함수
    s->top = -1;
}
int is_empty(Stack *s)
{ // 스택 비어있는지 확인 // underflow 방지
    return s->top == -1;
}

int is_full(Stack *s) // 스택이 꽉 찼는지 확인 // overflow 방지
{
    return s->top == MAX_LEN - 1;
}
void push(Stack *s, char c)
{
    if (is_full(s))
        return;
    s->data[++s->top] = c; // 그게 아니면 키값(c)을 스택에 추가해라
}

char pop(Stack *s)
{
    if (is_empty(s))
        return 0; // underflow 방지
    return s->data[s->top--];
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        char input[MAX_LEN + 1]; // null 문자를 위해서 +1
        scanf("%s", input);

        Stack left, right;
        init(&left);  // left 스택 초기화(세팅)
        init(&right); // right 스택 초기화(세팅)

        for (int i = 0; input[i]; i++)
        { // input[i] == '\0' 널문자 일때
            char c = input[i];
            if (c == '<')
            {
                if (!is_empty(&left))
                {
                    push(&right, pop(&left));
                }
            }
            else if (c == '>')
            {
                if (!is_empty(&right))
                {
                    push(&left, pop(&right));
                }
            }
            else if (c == '-')
            {
                if (!is_empty(&left))
                {
                    pop(&left);
                }
            }
            else
            {
                push(&left, c);
            }
        }

        // 왼쪽 스택 출력 (정방향)
        for (int i = 0; i <= left.top; i++)
        {
            putchar(left.data[i]);
        }
        // 오른쪽 스택 출력 (역방향)
        for (int i = right.top; i >= 0; i--)
        {
            putchar(right.data[i]);
        }
        putchar('\n');
    }
    return 0;
}