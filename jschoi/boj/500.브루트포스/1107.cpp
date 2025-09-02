#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_CHANNEL = 1000000;            // 최대 채널: 채널은 무한대, target의 범위는 50만, 시작은 100부터니까 넉넉히 100만으로 설정
vector<int> channels(MAX_CHANNEL, true);    // 한번에 갈 수 있는 채널. 갈 수 있으면 true
vector<bool> brokenBtn(10, false);          // true: 고장, false: 고장x
int start = 100;                            // 시작 채널
int target = 0;                             // 타겟 채널

// 함수 정리
int startChPressCnt();
int solution();
int usePlus();
int useMinus();

int main() {
    // 타겟 채널 입력
    cin >> target;

    // 고장난 버튼 개수
    int n = 0;
    cin >> n;

    // 고장난 버튼 입력
    for(int i = 0; i < n; i++){
        int btn;
        cin >> btn;
        brokenBtn[btn] = true;
    }

    // 채널별 가능한지 체크
    for(int i = 0; i <= MAX_CHANNEL; i++){
        int temp = i;
        bool check = true;

        if(i == 0 && brokenBtn[0]) check = false; // 0 채널 처리

        while(temp > 0){
            int idx = temp % 10;
            if(brokenBtn[idx]){
                check = false;
                break;
            }
            temp /= 10;
        }
        channels[i] = check;
    }

    // 최소 버튼 수 출력
    cout << min(startChPressCnt(), solution());
    return 0;
}

// 100에서 +, -만 눌러서 이동
int startChPressCnt(){
    return abs(start - target);
}

// 숫자 버튼 +, - 조합 최소
int solution(){
    if(start == target) return 0;                           // target이 시작 채널과 같다면
    if(channels[target]) return to_string(target).length(); // 버튼조작으로 모두 가능하면
    return min(usePlus(), useMinus());
}

// target 이상으로 가면서 + 버튼
int usePlus(){
    int i = target;
    for(; i <= MAX_CHANNEL; i++){
        if(channels[i]) break;
    }
    if(i > MAX_CHANNEL) return MAX_CHANNEL; // 없는 경우 큰 수 반환
    return abs(target - i) + to_string(i).length();
}

// target 이하로 가면서 - 버튼
int useMinus(){
    int i = target;
    for(; i >= 0; i--){
        if(channels[i]) break;
    }
    if(i < 0) return MAX_CHANNEL; // 없는 경우 큰 수 반환
    return abs(target - i) + to_string(i).length();
}