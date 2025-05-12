/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 // - 외부 루프에서는 현재 가격을 가리키는 인덱스를 증가시킵니다.
 // - 내부 루프에서는 미래 가격을 가리키는 인덱스를 증가시킵니다.
 // - 현재 가격이 미래 가격보다 더 싼 동안 가격이 떨어지지 않은 기간은 1초씩 증가시킵니다.
 // - 현재 가격보다 비싼 미래 가격을 만나면 내부 루프를 중단하고 다음 현재 가격으로 넘어갑니다.

#define MAX_STACK_SIZE 100000
int stack[MAX_STACK_SIZE];
int result[MAX_STACK_SIZE];
int top = -1;


int IsEmpty()
{
    if (top < 0)
        return true;
    else
        return false;
}
int IsFull()
{
    if (top >= MAX_STACK_SIZE - 1)
        return true;
    else
        return false;
}

void push(int value)
{
    if (IsFull())
        printf("스택이 가득 찼습니다.");
    else
        stack[++top] = value;
}

int pop()
{
    if (IsEmpty())
        printf("스택이 비었습니다.");
    else
        return stack[top--];
}

int main()
{
    int prices[5] = { 1, 2, 3, 2, 3 };

    for(int i = 4; i >= 0; i--)
    {
        push(prices[i]);
    }
    // stack[5] = {3, 2, 3, 2, 1}; prices 거꾸로 넣어주기

    int now_price = 0;
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        now_price = pop();// 현재 가격
        // pop : 모든 제어 경로에서 값을 반환하지는 않습니다. > 오류는 뜸 > 결과 잘 나옴
        //pop 도출값과 now_price 변수값이 모두 int 형일 때만 정상작동, 하나라도 다를 경우 오류
        count = 0;
        for (int j = top; j >= 0; j--)
        {

            if (now_price > stack[j])
            {
                count++; // 현재 가격보다 낮은
                break;
            }
            else
            {
                count++;
            }
        }
        result[i] = count;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100000

typedef struct
{
    int price;
    int idx;
} Element;

Element stack[MAX_STACK_SIZE];
int result[MAX_STACK_SIZE];
int top = -1;

// 스택이 비었는지 확인
bool isEmpty()
{
    return top < 0;
}

// 스택이 가득 찼는지 확인
bool isFull()
{
    return top >= MAX_STACK_SIZE - 1;
}

// 스택에 요소 추가
void push(Element value)
{
    if (isFull())
    {
        printf("스택이 가득 찼습니다.\n");
        exit(1);
    }
    stack[++top] = value;
}

// 스택에서 요소 제거 및 반환
Element pop()
{
    if (isEmpty())
    {
        printf("스택이 비었습니다.\n");
        exit(1);
    }
    return stack[top--];
}

int main()
{
    int prices[5] = {1, 2, 3, 2, 3};
    int n = 5;

    // 결과 배열 초기화
    for (int i = 0; i < n; i++)
    {
        result[i] = 0;
    }

    // 메인 로직: 스택을 이용해 가격이 떨어지는 시점 계산
    for (int i = 0; i < n; i++)
    {
        // 스택에 저장된 이전 가격보다 현재 가격이 더 낮아질 때까지 pop
        while (!isEmpty() && stack[top].price > prices[i])
        {
            Element e = pop();
            result[e.idx] = i - e.idx;
        }
        // 현재 가격과 인덱스를 스택에 push
        push((Element){prices[i], i});
    }

    // 스택에 남아있는 가격들은 끝까지 가격이 떨어지지 않은 것
    while (!isEmpty())
    {
        Element e = pop();
        result[e.idx] = (n - 1) - e.idx;
    }

    // 결과 출력
    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}