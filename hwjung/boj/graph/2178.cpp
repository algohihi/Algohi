#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

// 방문 확인 및 현재 몇 번째 호출인지 기록 int이중배열
int check[100][100];
// 사용자 입력값
bool arr[100][100];
// 큐 -> x, y좌표가 따로 있기 때문에 pair로 사용해야함
queue<pair<int,int>>que;

int n, m;

// 단지번호붙이기와 같이 각 방향에 대해 모두 확인하기 위한 값 선언
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
	// 시작 값은 1, 공통
	check[x][y] = 1;

	// que가 모두 빌 때까지 반복(확인할 수가 없을 때까지)
	// if 문에서 경계처리 하고 있어 사실상 1로 둬도 무관하긴함
	while (!que.empty()) {
		int a = que.front().first; // 호출한 x값
		int b = que.front().second; // 호출한 y값
		// 경계 도달시 return처리
		if (a == n && b == m) return;
		que.pop();

		// 각 방향에 대해 처리
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + a, ny = dy[i] + b;
			// 배열 범위를 초과하는지 체크
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			// 갈 수 있는 장소인지 && 이미 방문한 장소는 아닌지
			if (arr[nx][ny] && !check[nx][ny]) {
				// 현재 차례 +1 해서 저장
				check[nx][ny] = check[a][b]+1;
				// 현재 que 모두 처리 후 다음 호출
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
		// 한 줄 받아와 bool 배열 arr에 각각 저장
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	// 출발지점 설정 후 bfs 호출
	que.push(make_pair(0, 0));
	bfs(0, 0);

	cout << check[n - 1][m - 1] << '\n';
}