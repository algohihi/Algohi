
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 200000
long long n, k, t;
long long scale[MAX_NUM + 1];

typedef struct
{
    long long data[MAX_NUM];
    long long top;
} Stack;

void init(Stack* s)
{
    s->top = -1;
}

long long is_empty(Stack* s)
{
    return s->top == -1;
}

void push(Stack* s, long long c)
{
    s->data[++s->top] = c;
}

long long pop(Stack* s)
{
    if (is_empty(s)) return 0;
    return s->data[s->top--];
}

// ����Ʈ�� ���� �� �Լ�
// ����� ����������
//������������ �� �Ÿ� > return 1��-1�� �ٲٸ� �� 
int compare(const void* a, const void* b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;  //(�������) X�� Y���� ������ ������ ����
    if (x > y) return 1;   //(���) X�� Y���� ũ�� �ڷ� ����
    return 0;
}

int main() {
    //n: �ٴٿ� �ִ� ��� ������
    //k: ���� �� �ִ� �ִ� ������
    //t: ���� ���� ũ�� 
    scanf("%lld %lld %lld", &n, &k, &t);

    for (int i = 0; i < n; i++)
    {//scale : �չٴٿ� �ִ� ��� ũ�� 
        scanf("%lld", &scale[i]);
    }

    //  �ٽ�: O(n��) �� O(n log n) ���ķ� ����
    qsort(scale, n, sizeof(long long), compare);

    Stack sea;
    init(&sea);

    int i = 0;
    while (k > 0 && i < n)
    {
        // ���� �ܺ��� ���� ������ ���ÿ� push
        while (i < n && t > scale[i])
        {
            push(&sea, scale[i]);
            i++;
        }

        // ���ÿ��� ���� ū ������ �Ա�
        if (!is_empty(&sea))
        {
            long long eaten = pop(&sea);
            t += eaten;
            k--;
        }
        else
        {
            break;
        }
    }

    // ���� k�� �ְ� ���ÿ� �� ������ ��� �Ա�
    while (k > 0 && !is_empty(&sea))
    {
        long long eaten = pop(&sea);
        t += eaten;
        k--;
    }

    printf("%lld\n", t);
    return 0;
}





#include <string.h> // memcpy, memmove ��� // 8����Ʈ (64��Ʈ)
#include <stdlib.h> // malloc, free ���
//(�迭�̸�, ��Ұ���, ���ũ��, ���Լ��̸�)
void qsort(long long* scale, size_t n, size_t size, int (*compare)(const void*, const void*)) {
    if (n < 2) return;

    char* arr = (char*)scale;
    char* pivot = arr; // ù ��° ���Ҹ� �ǹ����� ���
    size_t i, j = 0;

    // �ӽ� ����
    char* tmp = (char*)malloc(size);

    // ��Ƽ��: �ǹ����� ���� ������ ������ �̵�
    for (i = 1; i < n; ++i) {
        if (compare(arr + i * size, pivot) < 0) {
            ++j;
            memcpy(tmp, arr + i * size, size);
            memmove(arr + size, arr, j * size);
            memcpy(arr, tmp, size);
        }
    }
    free(tmp);

    // ��������� �¿� �κ� ����
    qsort((long long*)arr, j, size, compare);
    qsort((long long*)(arr + (j + 1) * size), n - j - 1, size, compare);
}



memcpy(tmp, arr + i * size, size);
�� ���� �� ���� ����(arr + i * size)�� �ӽ� ����(tmp)�� �����մϴ�.
��, �̵���ų ���� �ӽ÷� �����մϴ�.

memmove(arr + size, arr, j* size);
�� �迭�� ����(j��) �����͸� �� ĭ �ڷ� �о��ݴϴ�.
��, �ǹ����� ���� ���� ������ �ֱ� ���� ������ ����ϴ�.

memcpy(arr, tmp, size);
�� �ӽ� ���ۿ� �ִ� ���� �迭�� �� ��(�ǹ� �ڸ�)�� �����մϴ�.
��, �ǹ����� ���� ���� �迭�� �պκ�(�ǹ� �ڸ�)�� ��ġ��ŵ�ϴ�.

