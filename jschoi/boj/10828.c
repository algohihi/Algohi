#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10000

// 구조체 정의
typedef int element;
typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
} Stack;

// 함수 선언
void init_stack(Stack *st);
int is_empty(Stack *st);
int is_full(Stack *st);
int size(Stack *st);
void push(Stack *st, element e);
element pop(Stack *st);
element peek(Stack *st);

int main(){
    Stack st;
    init_stack(&st);

    int cnt = 0;
    scanf("%d", &cnt);

    for(int i = 0; i < cnt; i ++){
        char cmd[10];
        scanf("%s", cmd);

        if(strcmp(cmd, "push") == 0){
            int num = 0;
            scanf("%d", &num);
            push(&st, num);
        }
        else if(strcmp(cmd, "pop") == 0) printf("%d\n", pop(&st));
        else if(strcmp(cmd, "top") == 0) printf("%d\n", peek(&st));
        else if(strcmp(cmd, "size") == 0) printf("%d\n", size(&st));
        else if(strcmp(cmd, "empty") == 0) printf("%d\n", is_empty(&st));
    }

    return 0;
}

// 함수 정의
void init_stack(Stack *st){
    st -> top = -1;
}
int is_empty(Stack *st){
    if(st -> top == -1) return 1;
    return 0;
}
int is_full(Stack *st){
    if(st -> top == MAX_STACK_SIZE -1 ) return 1;
    return 0;
}
int size(Stack *st){
    return st -> top + 1;
}
void push(Stack *st, element e){
    if(is_full(st)){
        return;
    }
    st -> top++;
    (*st).data[(*st).top] = e;
}
element pop(Stack *st){
    if(is_empty(st)){
        return -1;
    }
    return (*st).data[(*st).top--];
}
element peek(Stack *st){
    if(is_empty(st)){
        return -1;
    }
    return (*st).data[(*st).top];
}