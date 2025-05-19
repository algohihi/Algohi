

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack1[1000000];  // 스택 배열
int top1 = -1;      // 스택의 top을 가리키는 인덱스 (-1이면 빈 상태)

void push1(char x) {
    stack1[++top1] = x;
}

char pop1() {
    if (top1 == -1) return -1;
    return stack1[top1--];
}

int empty1() {
    return (top1 == -1) ? 1 : 0;
}

char peek1() {
    if (top1 == -1) return -1;
    return stack1[top1];
}


char stack2[1000000];  // 스택 배열
int top2 = -1;      // 스택의 top을 가리키는 인덱스 (-1이면 빈 상태)

void push2(char x) {
    stack2[++top2] = x;
}

char pop2() {
    if (top2 == -1) return -1;
    return stack2[top2--];
}

int empty2() {
    return (top2 == -1) ? 1 : 0;
}

char peek2() {
    if (top2 == -1) return -1;
    return stack2[top2];
}


int main() 
{
    int n,i,j, k, len;
    char pw[1000000] = { 0 };

    scanf("%d", &n);

    for ( i = 0; i < n; i++)
    {
        top1 = -1;
        top2 = -1;

        scanf("%s", pw);
        len = strlen(pw);

        for (j = 0; j < len; j++)
        {
            if (isalnum(pw[j]))  //문자, 숫자일 때 
            {
                push1(pw[j]); //1에 저장
            }
            else if (pw[j] == '-')   // '-'일 때
            {
                if (empty1() == 0)
                {
                    pop1();  // 1에 값이 있으면 삭제
                }
            }
            else if (pw[j] == '<')  // <일 떄(왼쪽으로 이동)
            {
                if (empty1() == 0)  // 1에 값이 있으면
                {
                    push2(pop1());  //1에 있는 거 빼서 2에 저장하면서 커서 이동
                }
            }
            else if (pw[j] == '>') // >일 때(오른쪽으로 이동)
                if (empty2() == 0)  //2에 값이 있으면
                {
                    push1(pop2());  //2에 있는 거 뺴서 1에 넣어주면서 커서 이동
                }
        }

        while (1) {
            if (empty2() == 1) break;
            push1(pop2());
        }
        
        for (int k = 0; k <= top1; k++) {
            printf("%c", stack1[k]);
        }
        printf("\n");
    }


    return 0;
}



========================================================


#include <stdio.h>
#include <string.h>

char left[1000000];  
char right[1000000];

int top1, top2;

int main() {
    int n;
    char pw[1000001];

    scanf("%d", &n);

    while (n--) 
    {
        scanf("%s", pw);  // pw 입력
        top1 = top2 = 0;  // 커서 가운데로 초기화

        for (int i = 0; pw[i]; i++) 
        {
            if (pw[i] == '<') 
            {
                if (top1 > 0) right[top2++] = left[--top1];  
                // 왼쪽 커서가 이동했으면 (left에 값이 있다는 뜻) -> 왼쪽 마지막 값(커서보다 한칸 앞이니까 전치)을 오른쪽으로 이동(하고 커서는 한칸 더 옆이니까 후치)
            }
            else if (pw[i] == '>') 
            {
                if (top1 > 0) left[top1++] = right[--top2];  
                // 오른쪽 커서가 이동했으면 (right에 값이 있다는 뜻) -> 오른쪽 마지막 값(제일 앞)을 왼쪽으로 이동(커서는 한 칸 더 옆이니까 후치
            }
            else if (pw[i] == '-') 
            {
                if (top1 > 0) top1--;  // 커서 -  = 삭제 !
            }
            else 
            {
                left[top1++] = pw[i]; // pw입력받은 건 left에 저장
            }
        }

        for (int i = 0; i < top1; i++) 
        {
            printf("%c", left[i]);  // 왼쪽 출력
        }

        for (int i = top2 - 1; i >= 0; i--)  
        // 스택은 쌓이는 거니까 left right 약간 책 펼치는 느낌쓰 -> right는 역순으로 꺼내야 맞는 순서
        {
            printf("%c", right[i]);  
        }

        printf("\n");
    }

    return 0;
}
