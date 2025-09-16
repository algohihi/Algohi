#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

// �湮 Ȯ�� �� ���� �� ��° ȣ������ ��� int���߹迭
int check[100][100];
// ����� �Է°�
bool arr[100][100];
// ť -> x, y��ǥ�� ���� �ֱ� ������ pair�� ����ؾ���
queue<pair<int,int>>que;

int n, m;

// ������ȣ���̱�� ���� �� ���⿡ ���� ��� Ȯ���ϱ� ���� �� ����
int dx[4] = { 1, -1, 0 , 0 };
int dy[4] = { 0, 0, 1 , -1 };

//
//void dfs(int x, int y, int count) {
//	check[x][y] = true;
//	for (int i = 0; i < 4; i++) {
//		int nx = dx[i] + x, ny = dy[i] + y;
//		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
//		if (arr[nx][ny] && !check[nx][ny]) {
//			dfs(nx, ny, count);
//		}
//	}
//}

void bfs(int x, int y) {
	// ���� ���� 1, ����
	check[x][y] = 1;

	// que�� ��� �� ������ �ݺ�(Ȯ���� ���� ���� ������)
	// if ������ ���ó�� �ϰ� �־� ��ǻ� 1�� �ֵ� �����ϱ���
	while (!que.empty()) {
		int a = que.front().first; // ȣ���� x��
		int b = que.front().second; // ȣ���� y��
		// ��� ���޽� returnó��
		if (a == n && b == m) return;
		que.pop();

		// �� ���⿡ ���� ó��
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + a, ny = dy[i] + b;
			// �迭 ������ �ʰ��ϴ��� üũ
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			// �� �� �ִ� ������� && �̹� �湮�� ��Ҵ� �ƴ���
			if (arr[nx][ny] && !check[nx][ny]) {
				// ���� ���� +1 �ؼ� ����
				check[nx][ny] = check[a][b]+1;
				// ���� que ��� ó�� �� ���� ȣ��
				que.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		// �� �� �޾ƿ� bool �迭 arr�� ���� ����
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	// ������� ���� �� bfs ȣ��
	que.push(make_pair(0, 0));
	bfs(0, 0);

	cout << check[n - 1][m - 1] << '\n';
}