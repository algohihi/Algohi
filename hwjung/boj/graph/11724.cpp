#include <iostream>
#include <vector>
using namespace std;
vector<int> arr[1001];
bool checkDfs[1001];

void dfs(int n) {
	checkDfs[n] = true;
	for (int i = 0; i < arr[n].size(); i++) {
		if (checkDfs[arr[n][i]] == false)
			dfs(arr[n][i]);
	}

}


int main() {
	int n; // 정점의 개수
	int m; // 간선의 개수
	
	int count = 0;
	cin >> n >> m;

	// 인접 리스트로의 구현	

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	// u, v <= n
	for (int i = 1; i <= n; i++) {
		if (checkDfs[i] == false) {
			dfs(i);
			count++;
		}
	}

	cout << count << '\n';
}