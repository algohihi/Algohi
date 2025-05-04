#include <stdio.h>

// 최대공약수 계산 함수 (유클리드 호제법)
// 원리 = 두 수의 최대공약수는 큰 수를 작은 수로 나눈 나머지와 작은 수의 최대공약수와 같다.
int gcd(int a, int b)
{ // gcd(sum_num, sum_den)
    while (b != 0)
    {                    // 분모가 0이 아닐때 (예 : a = 48, b =18)
        int tmp = a % b; // tmp = a를 b로 나눈 나머지 (예 : tmp = 12>6>0)
        a = b;           // b 값을 a에 할당 (a=18>12>6)
        b = tmp;         // 나머지 값을 b에 할당(b=12>6>0)
    }
    return a; // b가 0이 되면 a가 최대공약수
}

int main()
{
    int a_num, a_den, b_num, b_den;
    scanf("%d %d", &a_num, &a_den); // 첫 번째 분수 입력
    scanf("%d %d", &b_num, &b_den); // 두 번째 분수 입력

    // 분수 덧셈 계산
    int sum_num = a_num * b_den + b_num * a_den;
    int sum_den = a_den * b_den;

    // 기약분수로 약분
    int common = gcd(sum_num, sum_den);
    sum_num /= common;
    sum_den /= common;

    printf("%d %d", sum_num, sum_den);
    return 0;
}