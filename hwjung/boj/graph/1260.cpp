#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
bool checkDfs[1001];
bool checkBfs[1001];
vector<int> arr[1001];
queue<int> que;

void dfs(int n) {
	cout << n << " ";
	checkDfs[n] = true;
	for (int i = 0; i < arr[n].size(); i++) {
		if (checkDfs[arr[n][i]] == false)
			dfs(arr[n][i]);
	}
}

void bfs(int n) {
	checkBfs[n] = true;
	while (!que.empty()) {
		int a = que.front();
		que.pop();
		cout << a << " ";
		for (int i = 0; i < arr[a].size(); i++) {
			if (checkBfs[arr[a][i]] == false) {
				checkBfs[arr[a][i]] = true;
				que.push(arr[a][i]);
			}
		}
	}
	
}

int main() {
	int n; // 정점의 개수
	int m; // 간선의 개수
	int v; // 탐색 시작 번호

	cin >> n >> m >> v;

	// 인접 리스트로의 구현

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	// 문제 조건 : 오름 차순 정렬
	for (int i = 1; i <= n; i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	dfs(v);
	cout << '\n';
	que.push(v);
	bfs(v);
}