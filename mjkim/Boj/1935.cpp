#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

double stack[100];  // 값 넣을 배열
int top = -1;      // 스택의 top을 가리키는 인덱스 (-1이면 빈 상태)

void push(double x) {
	stack[++top] = x;
}

double pop() {
	if (top == -1) return -1;
	return stack[top--];
}


int main()
{
	int n, len, z = 0;
	double a, b;

	scanf("%d", &n);

	char str[101];
	scanf("%s", str);
	len = strlen(str);
	int num[26];

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < len; i++)
	{
		if (isupper(str[i]))
		{

			push(num[str[i] - 'A']);

		}
		else
		{
			a = pop();
			b = pop();

			if (str[i] == '+') push(b + a);

			else if (str[i] == '-') push(b - a);

			else if (str[i] == '*') push(b * a);

			else if (str[i] == '/') push(b / a);
		}

	}

	printf("%.2f", stack[top]);
	return 0;
}