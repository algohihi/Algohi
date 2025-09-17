#include <iostream>
#include <vector>
#include <queue>
#include <utility> // std::pair를 사용하기 위해 추가
using namespace std;

vector<vector<int>> values;
vector<vector<bool>> visited;

// 대각선까지 확인해야하니까 8방향
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int cnt = 0; // 섬의 개수

void bfs(int x, int y, int h, int w) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            // 이웃 노드가 지도 범위 내에 있고, 육지(값이 1)이며, 아직 방문하지 않았다면
            if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && values[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true; // 방문 처리
                q.push({nx, ny}); // 큐에 추가
            }
        }
    }
}

int main() {
    int w, h;
    while (cin >> w >> h) {
        // 종료 조건
        if (w == 0 && h == 0) break;

        // reset
        values.clear();
        values.resize(h + 2, vector<int>(w + 2, 0));

        visited.clear();
        visited.resize(h + 2, vector<bool>(w + 2, false));

        cnt = 0;

        // 입력 받기
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> values[i][j];
            }
        }

        // bfs
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                // 방문한 적 없고 육지라면
                if (values[i][j] == 1 && !visited[i][j]) {
                    cnt++; // 새로운 섬 발견
                    bfs(i, j, h, w); // 너비 우선 탐색 시작
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}