// 방향 없는 그래프 연결요소 개수 구하기

#include <iostream>
#include <vector>

using namespace std;

vector<int> a[1001]; // 간선 저장 
bool check[1001];  // 갔는지 안갔는지 확인


// dfs : 갈 수 있는 만큼 가다가 
// 인접 리스트 : 한 정점과 연결된 간선을 찾음

void dfs(int x)  // 인접리스트 이용한 구현
{
	check[x] = true;  // 지나간 곳으로 체크

	for (int i = 0; i < a[x].size(); i++)  // 간선 개수 만큼 돌아
	{
		int next = a[x][i];  // 연결된 정점 하나씩 확인

		if (check[next] == false)  // 안 간 곳 찾으면
		{
			dfs(next);  // 다음 정점으로 들어감
		}
	}
}

int main() 
{
	int n, m;
	cin >> n >> m;  // 정점이랑 간선 개수 입력 받고  6 5

	int u, v;

	for (int i = 0; i < m; i++)  // 간선 양 끝점 받고
	{
		cin >> u >> v;  // 1-2 2-5 5-1 3-4 4-6
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int components = 0;

	for (int i = 1; i <= n; i++)
	{
		if (check[i] == false)
		{
			dfs(i);
			components += 1;
		}
	}
	cout << components << '\n';

	return 0;
}