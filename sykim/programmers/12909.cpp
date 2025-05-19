#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// 여는 괄호 '('만 쌓아두고, 닫는 괄호 ')'를 만나면 pop해서 짝을 맞춤
// 스택이 비어 있다면: 모든 여는 괄호가 닫는 괄호와 짝을 맞췄다는 뜻 → 올바른 괄호
// 스택이 비어 있지 않다면: 짝이 맞지 않은 여는 괄호가 남았다는 뜻 → 올바르지 않은 괄호
#define MAX_LEN 100001

typedef struct
{
    char data[MAX_LEN];
    int top;
} Stack;

// 스택 초기화
void init(Stack *s)
{
    s->top = -1;
}

// 스택에 값 넣기
void push(Stack *s, char c)
{
    s->data[++(s->top)] = c;
}

// 스택에서 값 빼기
char pop(Stack *s)
{
    if (s->top == -1)
        return 0; // underflow 방지
    return s->data[(s->top)--];
}

// 스택이 비었는지 확인
// 스택이 비어 있으면 1(true), 아니면 0(false)를 반환
bool is_empty(Stack *s)
{
    return s->top == -1;
}

// 올바른 괄호 판별 함수
bool solution(const char *s)
{
    Stack st;
    init(&st);
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '(')
        { // 열린괄호냐? (맞다)) > push
            push(&st, '(');
        }
        else if (s[i] == ')')
        { // 닫는괄호라면..(아니다)
            if (is_empty(&st))
            { // > 스택 비어있냐?
                // 짝이 맞지 않는 닫는 괄호
                return false; // > (맞다) 응 비어있다~
            }
            pop(&st); // (아니다) > 안 비어 있다. > pop
        }
    }
    // 스택이 비어있으면 올바른 괄호
    return is_empty(&st); // 비어있으면 true 반환 / 아니면 false반환
}

// // 테스트용 main 함수
// int main() {
//     char input[MAX_LEN];
//     scanf("%s", input);

//     if (solution(input)) {
//         printf("true\n");
//     }
//     else {
//         printf("false\n");
//     }
//     return 0;
// }