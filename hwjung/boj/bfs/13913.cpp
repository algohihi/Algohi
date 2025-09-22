#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAXNUM 100001
// check
// first : 해당 n까지 최소도달시간 기록
// second : 이전 인덱스(수) 기록
vector<pair<int, int>> check(MAXNUM);


int bfs(int n, int end) {
	queue<int> b;
	if (n == end) return 0;
	//if (n > end) {
	//	return n - end;
	//}
	check[n] = { 1,n };
	b.push(n);
	while (!b.empty()) {
		int tmp = b.front();
		b.pop();

		if (tmp == end) return check[tmp].first - 1;

		// --로만 풀이 가능한 n > end에 대한 처리
		if (n > end) {
			if (tmp - 1 >= 0 && tmp - 1 < MAXNUM && !check[tmp - 1].first) {
				check[tmp - 1].first = check[tmp].first + 1;
				check[tmp - 1].second = tmp;
				b.push(tmp - 1);
			}
		}
		// 그 외의 경우 3가지 방법 모두 활용
		else {
			// -1 할 경우
			if (tmp - 1 >= 0 && tmp - 1 < MAXNUM && !check[tmp - 1].first) {
				check[tmp - 1].first = check[tmp].first + 1;
				check[tmp - 1].second = tmp;
				b.push(tmp - 1);
			}
			// * 2 할 경우
			if (tmp * 2 < MAXNUM && !check[tmp * 2].first) {
				check[tmp * 2].first = check[tmp].first + 1;
				check[tmp * 2].second = tmp;
				b.push(tmp * 2);
			}
			// + 1 할 경우
			if (tmp + 1 < MAXNUM && !check[tmp + 1].first) {
				check[tmp + 1].first = check[tmp].first + 1;
				check[tmp + 1].second = tmp;
				b.push(tmp + 1);
			}
		}
	}
	return check[end].first;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k) << '\n';

	vector<int> result;
	result.push_back(k);
	
	// 마지막 수가 n이 될 때까지 check의 back이 가리키는
	// 인덱스(second)를 result에 기록
	while (result.back() != n) {
		result.push_back(check[result.back()].second);
	}

	// vector가 모두 빌 때까지 출력
	while (!result.empty()) {
		cout << result.back() << " ";
		result.pop_back();
	}

	return 0;
}