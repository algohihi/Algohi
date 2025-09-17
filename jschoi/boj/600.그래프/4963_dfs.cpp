#include <iostream>
#include <vector>
#include <queue>   
using namespace std;

vector<vector<int>> values;
vector<vector<bool>> visited;

// 대각선까지 확인해야하니까 
int dx[] = { 1,  0, -1,  0,  1,  1, -1, -1 }; 
int dy[] = { 0,  1,  0, -1,  1, -1,  1, -1 };

int cnt = 0; // 섬의 개수

void dfs(int x, int y, int h, int w) {
    visited[x][y] = true;
    for(int i = 0 ; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(values[nx][ny] == 1 && !visited[nx][ny]){
            // 방문한 적 없고, 값이 1이라면 재귀
            dfs(nx, ny, h, w);
        }
    }
}

int main() {
    int w, h;
    while (cin >> w >> h) {
        // 종료 조건
        if(w == 0 && h == 0) break;

        // reset
        values.clear();
        values.resize(h+2, vector<int>(w+2, 0));

        visited.clear();
        visited.resize(h+2, vector<bool>(w+2, false));

        cnt = 0;

        // 입력 받기
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> values[i][j];
            }
        }

        // dfs
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                if (!visited[i][j] && values[i][j] == 1) {
                    cnt++;
                    dfs(i, j, h, w);
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}



