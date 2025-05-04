// strncmp(a, b, n) : 문자열 a와  문자열 b에서 n개의 크기 비교


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack
{
	int arr[10000];  // 명령 수
	int top;
}stack;

void createStack(stack* p);
void push(stack* p, int n);
int pop(stack* p);
int size(stack* p);
int empty(stack* p);
int top(stack* p);

int main()
{
    int value, n;
    char com[100]; // 정수 최대값 100000 맞춰줘야돼?
    stack stk;
    createStack(&stk);

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        fgets(com, sizeof(com), stdin); // (com, 100, 키보드) = "키보드에서 한 줄을 입력받아서, 최대 99글자까지 com에 저장해줘"

        if (strncmp(com, "push", 4) == 0) {  //입력받은 배열에서 앞에 4개가 push랑 일치하면  push 4
            // push 뒤의 숫자 추출
            sscanf(com + 5, "%d", &value);  // com[0]+5 'push '다음에 나오는 숫자를 value에 저장, 숫자 &로
            push(&stk, value);
        }
        else if (strncmp(com, "pop", 3) == 0) {
            printf("%d\n", pop(&stk));
        }
        else if (strncmp(com, "size", 4) == 0) {
            printf("%d\n", size(&stk));
        }
        else if (strncmp(com, "empty", 5) == 0) {
            printf("%d\n", empty(&stk));
        }
        else if (strncmp(com, "top", 3) == 0) {
            printf("%d\n", top(&stk));
        }
    }

    return 0;
}

void createStack(stack* p)
{
	p->top = -1;
}

void push(stack* p, int n) //  push(&stk, value);
{
	/*if (p->top == 999 )
		return;*/
	p->top++;
	p->arr[p->top] = n;
}

int pop(stack* p)  //  printf("%d\n", pop(&stk));
{
	if (p->top == -1)
		return -1;
	return p->arr[(p->top)--];
}

int size(stack* p)
{
	return (p-> top) + 1;
}

int empty(stack* p)
{
    return (p->top == -1) ? 1 : 0;
}

int top(stack* p)
{
	if (p->top == -1)
		return -1;
	return p->arr[p->top];
}
