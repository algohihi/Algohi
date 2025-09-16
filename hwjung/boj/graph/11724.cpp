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
	int n; // ������ ����
	int m; // ������ ����
	
	int count = 0;
	cin >> n >> m;

	// ���� ����Ʈ���� ����	

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