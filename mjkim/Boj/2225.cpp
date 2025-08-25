#include <iostream>

using namespace std;

int main()
{
    int n, k;  // ���� N, ���� K
    cin >> n >> k;

    int d[201][201] = { 0 };
    d[0][0] = 1;

    for (int i = 1; i <= k; i++) // k��
    {
        for (int j = 0; j <= n; j++) // ���� n�� �ǵ���
        {
            // ������ �ڸ��� ���� ���� l�̶�� ���� �� �� �տ� ���� ������ ���� n-l
            for (int l = 0; l <= j; l++)
            {
                d[i][j] += d[i - 1][j - l];
                d[i][j] %= 1000000000;
            }
        }
    }


    cout << d[k][n] << '\n';

    return 0;
}