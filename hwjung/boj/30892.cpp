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
#include<algorithm>
#include<stack>
using namespace std;

// 미래에 다시 풀어볼게요...

/* K번 먹는다 할때, 최적의 수가 되지 않음
int main() {
	long long n, k, t;
	cin >> n >> k >> t;
	long long* a = new long long[n];

	// 상어들의 크기를 받음
	for (int i = 0; i < n; i++) {
		cin >> *(a + i);
	}

	sort(a, a + n);
	stack<long long> st;
	
	//t보다 큰 애들 st에 저장, 먹을 수 있는 애들 중 가장 큰 얘 얌
	for (int i = n - 1; i >= 0; i--) {
		if ( t <= a[i]) {
			st.push(a[i]);
		}
		else {
			t += a[i];
			k--;
			//break;
		}
	}
	

	// pop으로인해 최대개수 k번째까지 못 먹을 수 있음
	for (int i = 0; i < k; i++) {
		bool ate = false;
		long long max = 0;
		while (!st.empty() && t > st.top()) {
			max = st.top();
			st.pop();
			ate = true;
		}
		if (ate) t += max;
		else break; // 더 이상 먹을 수 있는 상어가 없음
	}
	cout << t;
	delete[] a;
}
*/


// 상단 과정 그대로 진행
// 시간 초과
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