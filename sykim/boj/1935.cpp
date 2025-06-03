#include <stdio.h>  // 입출력
#include <stdlib.h> //문자열
#include <string.h> //표준함수
#include <ctype.h>
#include <math.h>

#define MAX 100

typedef struct
{ // 스택 구조체  정의 (실수형 데이터 저장)
    double data[MAX];
    int top;
} Stack;

void init(Stack *s)
{ // 초기화 함수
    s->top = -1;
}

int is_empty(Stack *s)
{ // 비었을때 검사
    return s->top == -1;
}

void push(Stack *s, double val)
{ // PUSH
    s->data[++(s->top)] = val;
}

double pop(Stack *s)
{ // POP
    if (is_empty(s))
    {
        exit(1);
    }
    return s->data[(s->top)--];
}

double calc(double a, double b, char op)
{ // 두 피연산자와 연산자를 받아 연산 결과 반환함수
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        printf("Unknown operator: %c\n", op);
        exit(1);
    }
}

int main()
{
    int n;
    char expr[101];
    double values[26];
    Stack s;
    init(&s);

    scanf("%d", &n);
    scanf("%s", expr);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &values[i]); // 입력 받아 피연산자 값 저장
    }

    int len = strlen(expr);
    for (int i = 0; i < len; i++)
    {
        char ch = expr[i];
        if ('A' <= ch && ch <= 'Z')
        {
            push(&s, values[ch - 'A']);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            double b = pop(&s);
            double a = pop(&s);
            push(&s, calc(a, b, ch));
        }
    } // 후위 표기식을 한 글자씩 읽으며, 피연산자면 값을 PUSH, 연산자면 두 값을 POP해서 연산 결과를 PUSH

    double result = pop(&s);
    printf("%.2lf\n", result);
    return 0; // 스택에 남은 결과를 소수 둘째자리까지 출력
}