#include <iostream>

using namespace std;

int main(){
    int n = 0;
    int k = 0;
    int cnt = 0;
    int measure = 0;

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            cnt++;
            measure = i;
        }
        if(k == cnt) break;
    }

    if(cnt < k) cout << 0;
    else cout << measure;

    return 0;
}