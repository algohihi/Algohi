#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int unit;
typedef struct {
	unit* data;
	int size;
} Stack;

void Push(Stack* st, int value) {
	st->data[st->size] = value;
	st->size++;
}

unit Pop(Stack* st) {
	if (st->size > 0) {
		return st->data[--st->size];
	}
	else {
		return -1;
	}
}

unit Top(Stack* st) {
	if (st->size > 0) {
		return st->data[st->size - 1];
	}
	else {
		return -1;
	}
}

int* solution(int prices[], size_t prices_len) {
	//malloc : 동적 메모리 할당, 즉 prices_len의 길이 만큼 할당하겠다
	//sizeof(int)를 곱해주어야 하는 이유는 malloc이 비트 단위이기 때문
	//사용 후에는 free로 반드시 해체해주어야 한다
	int* answer = (int*)malloc(sizeof(int) * prices_len);

	Stack st;
	st.size = 0;
	st.data = (unit*)malloc(sizeof(unit) * prices_len);

	//prices_len만큼 반복
	for (int i = 0; i < prices_len; i++) {
		//처음 수는 바로 저장
		//Top에 저장된 수 : 이전까지의 가장 큰 수 
		//-> Top과의 비교로 가격이 떨어졌는지 아닌지를 확인 할 수 있다.
		while (st.size > 0 && prices[Top(&st)] > prices[i]) {
			int topidx = Pop(&st);
			answer[topidx] = i - topidx;
		}
		Push(&st, i);
	}

	while (st.size > 0) {
		int topidx = Pop(&st);
		answer[topidx] = prices_len - topidx - 1;
	}

	free(st.data);
	return answer;
}


/* log확인 풀이
#include <iostream>

typedef int unit;
typedef struct
{
	unit* data;
	int size;
}Stack;

int* solution(int price[], size_t prices_len);
void Push(Stack* st, int value);
unit Pop(Stack* st);
unit Top(Stack* st);

int main()
{
	int price[] = { 1, 2, 3, 2, 3 };
	int* result = solution(price, 5);
	
	for (int i = 0; i < 5; i++) {
		std::cout << result[i] << " ";
	}

	free(result); // 할당을 해체
	return 0;
}

int* solution(int price[], size_t prices_len) {
	Stack st;
	st.size = 0;
	st.data = (unit*)malloc(sizeof(unit) * prices_len);
	int* answer = (int*)malloc(sizeof(int) * prices_len);

	for(int i = 0; i < prices_len; i++) {
		while (st.size > 0 && price[Top(&st)] > price[i]) {
			int topidx = Pop(&st);
			answer[topidx] = i - topidx;
		}
		Push(&st, i);
	}

	//개선 전
	//while (Top(&st) < prices_len) {
	//	for (int i = 1; i < prices_len; i++) {
	//		Push(&st, i - 1);
	//		if (price[Top(&st)] > price[i]) {
	//			answer[Top(&st)] = i - Top(&st);
	//			Pop(&st);
	//		}
		}
	}
	
	while(st.size > 0) {
		int topidx = Pop(&st);
		answer[topidx] = prices_len - topidx - 1;
	}

	//* 개선 전 - Pop을 사용하기 때문에 for문으로 돌릴 이유가 없음
	//for (int i = st.size - 1; i >= 0; i++) {
	//	answer[Top(&st)] = prices_len - Top(&st) -1;
	//}
	

	free(st.data);

	return answer;
}

void Push(Stack* st, int value) {
	st->data[st->size] = value;
	st->size++;
}

unit Pop(Stack* st) {
	if (st->size > 0) {
		return st->data[st->size-- - 1];
	}
	else {
		return -1;
	}
}

unit Top(Stack* st) {
	if (st->size > 0) {
		return st->data[st->size - 1];
	}
	else {
		return -1;
	}
}

*/

/*
int* solution(int price[], size_t prices_len) {
	int* answer = (int*)malloc(prices_len * sizeof(unit));
	Stack st;
	st.size = 0;
	st.data = (unit*)malloc(sizeof(unit) * prices_len);

	for(int i=0; i<prices_len; i++) {
		Push(&st, price[i]);
	}

	for (int i = 0; i < prices_len; i++) {

		int cnt = 0;
		int tmp = Pop(&st);
		if (tmp == -1) {
			answer[i] = 0;
			continue;
		}
		for(int j =0; j<st.size; j++) {
			cnt++;
			if (tmp < price[j]) {
				break;
			}
		}
		answer[i] = cnt;
	}

	free(st.data);
	return answer;
}*/