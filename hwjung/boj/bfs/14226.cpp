#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// 2���� ���� ����, -1�� �ʱ�ȭ
vector<vector<int>> check(1001, vector<int>(1001, -1));

int dfs(int end) {
	if (end == 2) return 2;
	queue<pair<int, int>> q; // first : ���� ��, second : clip
	check[1][0] = 0;
	q.push({ 1, 0 });
	while (!q.empty()) {
		int tmp = q.front().first;
		int clip = q.front().second;
		q.pop();
		if (tmp == end) return check[tmp][clip];
		// �ٿ��ֱ�
		if (tmp + clip <= 1000 && check[tmp + clip][clip] == -1) {
			check[tmp + clip][clip] = check[tmp][clip] + 1;
			q.push({ tmp + clip, clip });
		}
		// ����
		if (check[tmp][tmp] == -1) {
			check[tmp][tmp] = check[tmp][clip] + 1;
			q.push({ tmp, tmp });
		}
		// 1 ����
		if (tmp - 1 >= 0 && check[tmp - 1][clip] == -1) {
			check[tmp - 1][clip] = check[tmp][clip] + 1;
			q.push({ tmp - 1, clip });
		}
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	
	cout << dfs(n) << '\n';
}