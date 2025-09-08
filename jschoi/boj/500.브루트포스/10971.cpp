#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int main() {
    // 도시의 수 입력받기
    int n = 0;
    cin >> n;

    // 도시 이동 비용 저장할 2차원 벡터
    vector<vector<int>> cost(n, vector<int>(n, 0));

    // 이동 비용 입력받기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }
    
    // 최저 이동 비용
    int min_cost = numeric_limits<int>::max(); // int 타입의 최댓값으로 초기화해놓고

    // 무조건 시작은 0이므로, 1~(n-1)까지의 경우의 수만 확인하면 된다.
    // next_permutation을 사용하기위해 오름차순으로 vector 초기화
    vector<int> nums;
    for(int i = 1; i < n; i ++){
        nums.push_back(i);
    }

    // next_permutation 를 사용해 순열 조합을 모두 확인한다
    // do-while을 쓰는 이유는 첫 번째 순열(초기 상태)도 포함해서 모든 순열을 확인하기 위함
    do{
        int sum = 0;
        int now = 0;
        for(int next : nums){
            // 갈 수 없는 곳이라면 for문 멈추고, sum = -1
            if(cost[now][next] == 0){
                sum = -1;
                break;
            }
            // now -> next 의 cost를 sum에 합하기 
            sum += cost[now][next];
            // now reset -> 다음 항목을 위해 now를 next로
            now = next;
        }

        // sum이 -1이면 다음 순열 확인
        if(sum == -1) continue;

        // 출발 지점으로 돌아가는 비용 확인
        if(cost[now][0] == 0){
            // 돌아갈 수 없으면 다음 순열 확인
            continue;
        }else{
            sum += cost[now][0];
        }

        // sum이 -1이 아닐 때만 최소 비용 갱신
        min_cost = min(min_cost, sum);
    } while(next_permutation(nums.begin(), nums.end()));

    // 출력
    cout << min_cost;
}
