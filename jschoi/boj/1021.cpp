#include <iostream>
#include <vector>
#include <deque>
#include <algorithm> 

using namespace std;

void initDq(deque<int>& dq, int n);
void initVal(vector<int>& val, int m);

int main(){
    int n, m;
    cin >> n >> m;

    deque<int> dq;
    initDq(dq, n);

    vector<int> arr;
    initVal(arr, m);

    int cnt = 0;

    for(int i = 0; i < m; i++){        
        int idx = find(dq.begin(), dq.end(), arr[i]) - dq.begin();
        
        // 앞부터?
        if(idx <= dq.size() / 2) {
            while(dq.front() != arr[i]) {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        } else {
            // 뒤부터?
            while(dq.front() != arr[i]) {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
        dq.pop_front(); // 뽑기 완료
    }

    cout << cnt;
}

void initDq(deque<int>& dq, int n ){
    for(int i = 1; i <= n; i++){
        dq.push_back(i);
    }
}

void initVal(vector<int>& val, int m){
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        val.push_back(temp);
    }
}
