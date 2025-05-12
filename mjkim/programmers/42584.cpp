// 1-1 이중 for문

#include <stdio.h>

int main() {
    int prices[] = { 1, 2, 3, 2, 3 };
    int len = sizeof(prices) / sizeof(prices[0]);
    int answer[100000] = { 0 };  // 최대 크기 가정

    // 각 시점 i에 대해
    for (int i = 0; i < len; i++) 
    {
        int count = 0;
        // i 이후 시점들을 순회
        for (int j = i + 1; j < len; j++) {
            count++;
            if (prices[j] < prices[i]) {
                break; // 가격이 떨어지면 중단
            }
        }
        answer[i] = count;
    }

    // 결과 출력
    for (int i = 0; i < len; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}



// 1-2 이중 for문(제출용)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) 
{
    // 동적 할당으로 결과 배열 생성
    int* answer = (int*)malloc(sizeof(int) * prices_len);

    // 각 시점에서 가격이 떨어지지 않은 시간을 계산
    for (size_t i = 0; i < prices_len; i++) 
    {
        answer[i] = 0;
        for (size_t j = i + 1; j < prices_len; j++) 
        {
            answer[i]++;
            if (prices[j] < prices[i]) 
            {
                break; // 가격이 떨어지면 그 시점에서 멈춤
            }
        }
    }

    return answer; // 결과 반환
}

// 테스트용 메인 함수
int main() 
{
    int prices[] = { 1, 2, 3, 2, 3 };             // 입력 배열
    size_t len = sizeof(prices) / sizeof(int);  // 길이 계산

    int* result = solution(prices, len);        // 함수 호출

    // 결과 출력
    for (size_t i = 0; i < len; i++) 
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);  // 동적 할당 해제
    return 0;
}

==========================================================================

// 2-1 스택
#include <stdio.h>

typedef struct {
    int price;
    int index;
} Node;

Node stack[100000];
int topIdx = -1;

void push(int price, int index) 
{
    topIdx++;
    stack[topIdx].price = price;
    stack[topIdx].index = index;
}

Node pop() 
{
    return stack[topIdx--];
}

int isEmpty() 
{
    return topIdx == -1;
}

Node top() 
{
    return stack[topIdx];
}

int main() 
{
    int prices[] = { 1, 2, 3, 2, 3 };
    int len = sizeof(prices) / sizeof(prices[0]);
    int answer[100000] = { 0 };  // 최대 크기 가정

    // 첫 번째 값 push
    push(prices[0], 0);

    for (int i = 1; i < len; i++) 
    {
        while (!isEmpty() && top().price > prices[i]) // 가격이 떨어졌을 때 스택에서 빼며 정답 계산
        {
            Node temp = pop();
            answer[temp.index] = i - temp.index;
        }
        // 현재 값 push
        push(prices[i], i);
    }

    // 스택에 남은 값들 처리 (끝까지 가격이 떨어지지 않은 경우)
    while (!isEmpty()) 
    {
        Node temp = pop();
        answer[temp.index] = len - 1 - temp.index;
    }

    // 결과 출력
    for (int i = 0; i < len; i++) 
    {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}


// 2-2 스택 제출용
...
