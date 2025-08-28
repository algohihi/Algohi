#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(vector<int> height, int sum);
int main() {
    int spySum = 0;             // 아홉 난쟁이의 키 합
    int realSum = 100;          // 일곱 난쟁이의 키 합
    vector<int> height(9);      // 아홉 난쟁이의 키를 받을 벡터

    // input
    for(int i = 0; i < 9; i++){
        int n;
        cin >> n;
        spySum += n;
        height[i] = n;
    }

    // sort
    sort(height.begin(), height.end());

    // find
    solution(height, spySum-realSum);
    return 0;
}

// Idea: 아홉 난쟁이의 키의 합(spySum) - 일곱 난쟁이의 합(realSum) = 키 2개의 합을 찾는다
void solution(vector<int> height, int sum){
    int spy1 = -1;
    int spy2 = -1;

    // find spy
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if(height[i] + height[j] == sum){
                spy1 = i;
                spy2 = j;
                break;
            }
        }
        if(spy1 != -1) break;
    }

    // print
    for(int i = 0; i < 9; i++){
        if(i == spy1) continue;
        if(i == spy2) continue;
        cout << height[i] << endl;
    }
}