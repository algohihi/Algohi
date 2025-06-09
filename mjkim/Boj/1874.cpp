#include <stdio.h>
#define MAX 100001  // ���� �ִ� ���� + ���� ����

int stack[MAX];        // �������� ����� �迭
int top = -1;          // ���� top ��ġ

// ���ÿ� ���� push + ���� ���
void push(int x)
{
    stack[++top] = x;     // ���ÿ� ���� �߰�

}

// ���ÿ��� ���� pop + ���� ���
int pop()
{
    return stack[top--];    
}

int main()
{
    int n, arr[MAX];        // n: ���� ����, arr[]: �Է� ����

    scanf("%d", &n);        // ���� ���� �Է�

    // ���� �Է� �ޱ� (0�� �ε������� ���)
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int num = 1;  // ���� push�� ���� (1���� ����)
    int idx = 0;  // ���� �� ���� ���� �ε���

    // ���� ��ü ó���� ������ �ݺ�
    while (idx < n)
    {
        // ������ ����ų�, ���� top�� arr[idx]���� ������ push
        if ((top == -1 || stack[top] < arr[idx]) && num <= n)
        {
            push(num++);  // ���� push�ϰ� ���� ���� �غ�
            printf("+\n");
        }
        // ���� top�� arr[idx]�� ������ pop
        else if (stack[top] == arr[idx])
        {
            pop();    // ��ǥ ���� pop
            printf("-\n");
            idx++;    // ���� ������ �̵�
        }
        // ���� top�� ��ǥ���� ũ�� ���� ���� �Ұ�
        else
        {
            printf("NO\n");
            return 0;  // �����ϰ� ����
        }
    }

    return 0;
}






// ����ʰ�����
// ����� �迭�� ����ߴٰ� ����ϸ� �Ǵ°ǰ�

#include <stdio.h>
#define MAX 100001  // ���� �ִ� ���� + ���� ����

int stack[MAX];        // �������� ����� �迭
int top = -1;          // ���� top ��ġ

char output[MAX * 2];  // ��� ���
int outidx = 0;       // ��� �迭 �ε���


// ���ÿ� ���� push + ���� ���
void push(int x)
{
    stack[++top] = x;     // ���ÿ� ���� �߰�
    output[outidx++] = '+';

}

// ���ÿ��� ���� pop + ���� ���
int pop()
{
    output[outidx++] = '-';
    return stack[top--];
}

int main()
{
    int n, arr[MAX];        // n: ���� ����, arr[]: �Է� ����

    scanf("%d", &n);        // ���� ���� �Է�

    // ���� �Է� �ޱ� (0�� �ε������� ���)
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int num = 1;  // ���� push�� ���� (1���� ����)
    int idx = 0;  // ���� �� ���� ���� �ε���

    // ���� ��ü ó���� ������ �ݺ�
    while (idx < n)
    {
        // ������ ����ų�, ���� top�� arr[idx]���� ������ push
        if ((top == -1 || stack[top] < arr[idx]) && num <= n)
        {
            push(num++);  // ���� push�ϰ� ���� ���� �غ�
        }
        // ���� top�� arr[idx]�� ������ pop
        else if (stack[top] == arr[idx])
        {
            pop();    // ��ǥ ���� pop
            idx++;    // ���� ������ �̵�
        }
        // ���� top�� ��ǥ���� ũ�� ���� ���� �Ұ�
        else
        {
            printf("NO\n");
            return 0;  // �����ϰ� ����
        }
    }

    // ���� ��� ��� (+, -)
    for (int i = 0; i < outidx; i++) {
        printf("%c \n", output[i]);
    }

    return 0;
}




