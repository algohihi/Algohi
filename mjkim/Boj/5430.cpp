#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {

    // 입출력 속도를 높이기 위한 것이라 함
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // 총 반복 횟수
    cin >> t;

    while (t--) {
        string p, arr;
        int n;
        deque<int> x;
        int reversed = 0;
        bool isError = false;

        cin >> p;  //함수RD
        cin >> n;  // 배열 크기

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            x.push_back(num);
        }

        for (int i = 0; i < p.size(); i++) {

            // R이면
            if (p[i] == 'R') {
                reversed = 1 - reversed;  //반대
            }

            // D일 떄 
            else if (p[i] == 'D') {

                // 비어있으면 error
                if (x.empty()) {
                    isError = true;
                    break;
                }

                if (reversed) x.pop_back(); // 역방향이면 뒤에서 팝해주고
                else x.pop_front();  // 순방향이면 앞에서 팝
            }
        }

        // 결과 출력
        if (isError) {
            cout << "error\n";
        }

        else {
            cout << "[";

            // 역방향 출력
            if (reversed) {
                for (int i = x.size() - 1; i >= 0; i--) {
                    cout << x[i];
                    if (i != 0) cout << ",";
                }
            }

            // 순반향 출력
            else {
                for (int i = 0; i < x.size(); i++) {
                    cout << x[i];
                    if (i != x.size() - 1) cout << ", ";
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}

// 이래 했을 때 잘 출력되는데 틀렸다길래 chat한테 물어봤는데 
// 입력 조건이 [1, 2, 3, 4]로 문자열 형식으로 받아야 된대서 다시..
// 그 부분은 도움을 조금 받았슴다.
=======================================================


#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    
    // 입출력 속도를 높이기 위한 것이라 함
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // 총 반복 횟수
    cin >> t;

    while (t--) {
        string p, arr;
        int n;
        deque<int> x;
        int reversed = 0;
        bool isError = false;

        cin >> p;  //함수RD
        cin >> n;  // 배열 크기

        cin >> arr;  // 문자열을 입력받아서

        // 배열 파싱
        string num = "";
        for (char c : arr) {              // == for (int i = 0; i < arr.size(); i++)  { char c = arr[i]...
            if (isdigit(c)) num += c; //숫자면 이어붙여서 num에 저장 ('12'같은 경우 1, 2 따로가 아니라 한번에 입력받으려고) 

            else if (!num.empty()) {
                x.push_back(stoi(num));  //num을 정수변환해서 푸시
                num = ""; // 초기화
            }
        }

        for (int i = 0; i < p.size(); i++) {
            
            // R이면
            if (p[i] == 'R') {
                reversed = 1 - reversed;  //반대
            }

            // D일 떄 
            else if (p[i] == 'D') {
                
                // 비어있으면 error
                if (x.empty()) {
                    isError = true;
                    break;
                }

                if (reversed) x.pop_back(); // 역방향이면 뒤에서 팝해주고
                else x.pop_front();  // 순방향이면 앞에서 팝
            }
        }

        // 결과 출력
        if (isError) {
            cout << "error\n";
        }

        else {
            cout << "[";

            // 역방향 출력
            if (reversed) {
                for (int i = x.size() - 1; i >= 0; i--) {
                    cout << x[i];
                    if (i != 0) cout << ",";
                }
            }

            // 순반향 출력
            else {
                for (int i = 0; i < x.size(); i++) {
                    cout << x[i];
                    if (i != x.size() - 1) cout << ",";
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}
