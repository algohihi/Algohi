#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
bool arr[25][25];
bool check[25][25];
vector<int> countNum;

int dx[4] = { 1, -1, 0 , 0 };
int dy[4] = { 0, 0, 1 , -1 };

int n;

void dfs(int x, int y, int count) {
	check[x][y] = true;
	countNum[count]++;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x, ny = dy[i] + y;
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (arr[nx][ny] && !check[nx][ny]) {
			dfs(nx, ny, count);
		}
	}
	
	/*
	if (arr[x][y + 1] && !check[x][y + 1]) {
		dfs(x, y + 1);
	}
	if (arr[x+1][y] && !check[x+1][y]) {
		dfs(x + 1, y);
	}
	if (arr[x - 1][y] && !check[x - 1][y]) {
		dfs(x - 1, y);
	}
	if (arr[x][y-1] && !check[x][y-1]) {
		dfs(x , y-1);
	}*/
}


// bfs로도 풀이연습하기...
int main() {
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			
			arr[i][j] = s[j] - '0';
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == false && arr[i][j] == true) {
				countNum.push_back(0);
				dfs(i,j, cnt++);
			}
		}
	}
	cout << cnt << '\n';
	
	sort(countNum.begin(), countNum.end());

	for (int i = 0; i<cnt; i++) {
		cout << countNum[i] << '\n';
	}
}