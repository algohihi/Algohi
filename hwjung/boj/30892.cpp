/*
* {먹을 수 있는 수를 모두 stack에 저장. max에 top을 담고, pop하면서 비교
* 마지막에 남은 max를 T에게 더해줌
* 더해준 값은 제거
* 더한 T를 기준으로 위의 과정을 다시 반복 }
* 총 k번을 반복하고, 가장 처음의 먹을 수 있는 수를 저장하는 과정를 마친 뒤 
* stack emtpy =1 이라면 과정을 종료하고 T를 출력한다.
*/
#include<iostream>
#include<vector>
using namespace std;

int main() {




}



// 상단 과정 그대로 진행
// 시간 초과 : stack만으로 푸는 게 가능한가...??? 
/*
#include<iostream>
#include<stack>
using namespace std;

int main() {
	long n, k, t;
	cin >> n >> k >> t;
	long long* a = new long long[n];
	
	// 상어들의 크기를 받음
	for (int i = 0; i < n; i++) {
		cin >> *(a + i);
	}

	stack<long long> st;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			if (t > *(a + j)) {
				st.push(*(a + j));
				//cout << *(a + j) << " ";
			}
		}

		if (st.empty()) break;

		long long max = st.top(); st.pop();
		
		while(!st.empty()) {
			if (max < st.top()) max = st.top();
			st.pop();
		}
		t += max;

		for (int j = 0; j < n; j++) {
			if (*(a + j) == max) { 
				*(a + j) = 0;
				break;
			}
		}
	}
	cout << t;
}
*/