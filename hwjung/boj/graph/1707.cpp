#include <iostream>
#include <vector>
using namespace std;
vector<int> check(20001);
vector<int> arr[20001];

bool dfs(int n, int next) {
	bool result = true;
	check[n] = next;
	for (int i=0; i < arr[n].size(); i++) {
		if (check[arr[n][i]] == 0) {
			int nc = (next == 1 ? 2 : 1);
			result &= dfs(arr[n][i], nc);
		}
		else if(check[arr[n][i]] == check[n])
			return false;
	}
	return result;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		// 비 연결형 가능 형태

		bool ok = true;
		for (int i = 1; i <= n && ok; ++i) {
			if (check[i] == 0) ok &= dfs(i, 1);
		}

		if (ok) {
			cout << "YES"<<'\n';
		}
		else {
			cout << "NO" << '\n';
		}

		// clear쓰면 공간 유지 x 
		// check.clear();
		// arr->clear();

		for (int i = 1; i <= n; i++) {
			check[i] = 0;
			arr[i].clear();
		}
	}

}