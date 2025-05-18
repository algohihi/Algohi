/*1. 문자열 입력 받기(프로그래머스라 필요없긴 합니다) s = "(()("
2. 반복문 몇 번 돌릴 지 = s 의 길이
3. 반복문 시작
3-1. i번째 문자를 꺼내서 열린 괄호인지 확인
3-1-1. 맞다 -> stack에 push
3-1-2. 아니다 -> stack이 비어있는가?
3-1-21. 맞다 -> return false
3-1-22. 아니다 -> stack에서 pop
4. stack이 비어있는지 확인
4-1. 비었을 경우 return true
4-2. 아닌 경우 return false*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool solution(const char* s) {
    int len = strlen(s);
    char* stack = malloc(len);  // 동적 메모리 할당
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            stack[++top] = '(';  // '(' 맞으면 push
        }
        else 
        {
            if (top == -1) 
            {
                free(stack);     // 메모리 해제
                return false;    // 비었으면 flase
            }
            top--;               // 있으면 pop
        }
    }

    bool result = (top == -1);  // 스택이 비었으면 true
    free(stack);
    return result;
}

