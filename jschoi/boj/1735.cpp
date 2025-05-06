#include <iostream>
#include <vector>
#include <numeric> 

using namespace std;

int getGcd(int n1, int n2);

int main(){
    vector<int> arr;
    int b1 = 0, u1 = 0;
    int b2 = 0, u2 = 0;
    int b3 = 0, u3 = 0;

    cin >> u1 >> b1;
    cin >> u2 >> b2;

    b3 = b1 * b2;
    u3 = (u1*b2) + (u2*b1);

    // int gcdNum = gcd(b3, u3);
    int gcdNum = getGcd(b3, u3);
    cout << u3/gcdNum << " " << b3/gcdNum;
    return 0;
}

// 유클리드 호제법: 최대 공약수(gcd)를 구하는 방법
// 정리: https://www.notion.so/1eb8c82ccfab807f8f01faa77c3bfb50?pvs=4
int getGcd(int n1, int n2){
    while(n2 != 0){
        int temp = n1 % n2;
        n1 = n2;
        n2 = temp;
    }
    return n1;
}