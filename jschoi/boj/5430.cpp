#include <iostream>  
#include <deque>     
#include <string>    
#include <cctype>    


using namespace std;

int main() {

    // 테스트 케이스 개수 입력 받기 
    int testCnt;
    cin >> testCnt;


    while (testCnt--) {
        string cmdList, arr;
        int n;
        cin >> cmdList >> n >> arr; // 명령어, 숫자 갯수, 숫자 배열 

        deque<int> dq;
        string num = "";
        for (char c : arr) {
            if (isdigit(c)) {
                num += c;
            } else if (!num.empty()) {
                // , 이나 [,] 이면 이어붙이기 멈추고 push
                dq.push_back(stoi(num));
                num = ""; // num 다시 초기화
            }
        }

        // 명령어 확인하고 진행
        bool reverse = false;
        bool error = false;
        for (char cmd : cmdList) {
            if (cmd == 'R') {
                // 실제로 뒤집지는 않고, 상태에따라서 어디서부터 pop할지 기준으로 삼음
                reverse = !reverse;
            } else {  // cmd == 'D'
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (!reverse){
                    dq.pop_front();
                }
                else{
                    dq.pop_back();
                }
            }
        }

        // 결과 출력
        if (error) {
            cout << "error\n";
        } else {
            cout << '[';
            if (!dq.empty()) {
                // 실제로 뒤집지 X, 출력
                if (!reverse) {
                    for (size_t i = 0; i < dq.size(); ++i) {
                        if (i) cout << ',';
                        cout << dq[i];
                    }
                } else {
                    for (size_t i = dq.size(); i-- > 0;) {
                        if (i != dq.size() - 1) cout << ',';
                        cout << dq[i];
                    }
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}
