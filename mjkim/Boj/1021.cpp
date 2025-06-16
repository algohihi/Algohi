#include <iostream>
#include <cstdlib>

using namespace std;

//구조체 선언
typedef struct queue {
    int* arr;
    int front;
    int rear;
    int count;
    int capacity;
} queue;

//함수언
void queueInit(queue* pQue, int size);
void enqueue(queue* pQue, int data);
int dequeue(queue* pQue);
void rotateLeft(queue* pQue);
void rotateRight(queue* pQue);
int findIndex(queue* pQue, int target);
void freeQueue(queue* pQue);

int main() {
    queue que;
    int n, m;

    //n, m입력받아서
    cin >> n >> m;

    //구조체 초기화
    queueInit(&que, n);

    // 큐에 1 ~ n 저장
    for (int i = 1; i <= n; i++) {
        enqueue(&que, i);
    }

    // 뽑을 숫자들
    int* idx = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        cin >> idx[i];
    }

    int total = 0;

    for (int i = 0; i < m; i++) {
        int target = idx[i];
        int pos = findIndex(&que, target); // 큐의 현재 상태에서 target의 위치

        //큐의 가운데를 기준으로 target이 앞쪽에 있으면 왼쪽 회전, 뒤쪽이면 오른쪽 회전을 선택
        if (pos <= que.count / 2) {
            // 왼쪽 회전
            for (int j = 0; j < pos; j++) {
                rotateLeft(&que);
                total++;
            }
        }
        else {
            // 오른쪽 회전
            for (int j = 0; j < que.count - pos; j++) {
                rotateRight(&que);
                total++;
            }
        }

        dequeue(&que); // 맨 앞 요소 꺼내기
    }

    //출력
    cout << total << endl;

    free(idx);
    freeQueue(&que);
    return 0;
}

// 큐 초기화
void queueInit(queue* pQue, int size) {
    pQue->arr = (int*)malloc(sizeof(int) * size);
    pQue->front = 0;
    pQue->rear = 0;
    pQue->count = 0;
    pQue->capacity = size;
}

// 삽입
void enqueue(queue* pQue, int data) {
    if (pQue->count == pQue->capacity) return; // overflow 생략

    pQue->arr[pQue->rear] = data;
    pQue->rear = (pQue->rear + 1) % pQue->capacity;
    pQue->count++;
}

// 삭제
int dequeue(queue* pQue) {
    if (pQue->count == 0) return -1; // underflow 생략

    int val = pQue->arr[pQue->front];
    pQue->front = (pQue->front + 1) % pQue->capacity;
    pQue->count--;
    return val;
}

// 왼쪽으로 한 칸 회전 
void rotateLeft(queue* pQue) {
    int val = dequeue(pQue); //맨 앞 요소를 빼서 val에 저장
    enqueue(pQue, val);  //val을 다시 삽입
}

// 오른쪽으로 한 칸 회전 (뒤에서 하나 빼서 앞으로 넣기)
void rotateRight(queue* pQue) {
    if (pQue->count == 0) return;  //요소가 없으면 리턴

    // rear 한 칸 뒤로 (마지막 요소 위치)
    pQue->rear = (pQue->rear - 1 + pQue->capacity) % pQue->capacity;
    int val = pQue->arr[pQue->rear];

    // front 한 칸 뒤로
    pQue->front = (pQue->front - 1 + pQue->capacity) % pQue->capacity;
    pQue->arr[pQue->front] = val;


}

// 원하는 값이 큐의 몇 번째 위치에 있는지 (앞에서부터 거리)
int findIndex(queue* pQue, int target) {
    for (int i = 0; i < pQue->count; i++) {  //0부터 요소 개수만큼 반복
        //front부터 시작해서 i칸 떨어진 위치 = (front + i) % capacity 나머지만큼
        int idx = (pQue->front + i) % pQue->capacity;
        if (pQue->arr[idx] == target)
            return i;
    }
    return -1;

    /*큐 원소 : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
            index :       0        2           1
            타겟이 2면  9 + i % 10 = 0 => i = 1을 리턴*/
}

// 메모리 해제
void freeQueue(queue* pQue) {
    free(pQue->arr);
}
