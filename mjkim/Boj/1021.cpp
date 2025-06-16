#include <iostream>
#include <cstdlib>

using namespace std;

//����ü ����
typedef struct queue {
    int* arr;
    int front;
    int rear;
    int count;
    int capacity;
} queue;

//�Լ���
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

    //n, m�Է¹޾Ƽ�
    cin >> n >> m;

    //����ü �ʱ�ȭ
    queueInit(&que, n);

    // ť�� 1 ~ n ����
    for (int i = 1; i <= n; i++) {
        enqueue(&que, i);
    }

    // ���� ���ڵ�
    int* idx = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        cin >> idx[i];
    }

    int total = 0;

    for (int i = 0; i < m; i++) {
        int target = idx[i];
        int pos = findIndex(&que, target); // ť�� ���� ���¿��� target�� ��ġ

        //ť�� ����� �������� target�� ���ʿ� ������ ���� ȸ��, �����̸� ������ ȸ���� ����
        if (pos <= que.count / 2) {
            // ���� ȸ��
            for (int j = 0; j < pos; j++) {
                rotateLeft(&que);
                total++;
            }
        }
        else {
            // ������ ȸ��
            for (int j = 0; j < que.count - pos; j++) {
                rotateRight(&que);
                total++;
            }
        }

        dequeue(&que); // �� �� ��� ������
    }

    //���
    cout << total << endl;

    free(idx);
    freeQueue(&que);
    return 0;
}

// ť �ʱ�ȭ
void queueInit(queue* pQue, int size) {
    pQue->arr = (int*)malloc(sizeof(int) * size);
    pQue->front = 0;
    pQue->rear = 0;
    pQue->count = 0;
    pQue->capacity = size;
}

// ����
void enqueue(queue* pQue, int data) {
    if (pQue->count == pQue->capacity) return; // overflow ����

    pQue->arr[pQue->rear] = data;
    pQue->rear = (pQue->rear + 1) % pQue->capacity;
    pQue->count++;
}

// ����
int dequeue(queue* pQue) {
    if (pQue->count == 0) return -1; // underflow ����

    int val = pQue->arr[pQue->front];
    pQue->front = (pQue->front + 1) % pQue->capacity;
    pQue->count--;
    return val;
}

// �������� �� ĭ ȸ�� 
void rotateLeft(queue* pQue) {
    int val = dequeue(pQue); //�� �� ��Ҹ� ���� val�� ����
    enqueue(pQue, val);  //val�� �ٽ� ����
}

// ���������� �� ĭ ȸ�� (�ڿ��� �ϳ� ���� ������ �ֱ�)
void rotateRight(queue* pQue) {
    if (pQue->count == 0) return;  //��Ұ� ������ ����

    // rear �� ĭ �ڷ� (������ ��� ��ġ)
    pQue->rear = (pQue->rear - 1 + pQue->capacity) % pQue->capacity;
    int val = pQue->arr[pQue->rear];

    // front �� ĭ �ڷ�
    pQue->front = (pQue->front - 1 + pQue->capacity) % pQue->capacity;
    pQue->arr[pQue->front] = val;

    /*front = 9
            rear = 0

            val = arr[9] = 10
            arr[8] = val = 10*/
}

// ���ϴ� ���� ť�� �� ��° ��ġ�� �ִ��� (�տ������� �Ÿ�)
int findIndex(queue* pQue, int target) {
    for (int i = 0; i < pQue->count; i++) {  //0���� ��� ������ŭ �ݺ�
        //front���� �����ؼ� iĭ ������ ��ġ = (front + i) % capacity ��������ŭ
        int idx = (pQue->front + i) % pQue->capacity;
        if (pQue->arr[idx] == target)
            return i;
    }
    return -1;

    /*ť ���� : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
            index :       0        2           1
            Ÿ���� 2��  9 + i % 10 = 0 => i = 1�� ����*/
}

// �޸� ����
void freeQueue(queue* pQue) {
    free(pQue->arr);
}