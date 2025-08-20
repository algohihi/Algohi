#include <iostream>
using namespace std;

int d[31] = { 1,0,3 }; // d[0]=1, d[1]=0, d[2]=3

int main() {
    int n;
    cin >> n;

    for (int i = 4; i <= n; i += 2) {
        d[i] = 3 * d[i - 2];
        for (int j = 0; j <= i - 4; j += 2)
            d[i] += 2 * d[j];
    }

    cout << d[n] << "\n";
}