#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool arr[2000][2000]; // 인접행렬 
vector<int> g[2000]; // 인접리스트

int main() {
	int node, edge;
	cin >> node >> edge;
	
	vector<pair<int, int>> edges; // 간선 리스트
	for (int i = 0; i < edge; i++) {
		int from, to;
		cin >> from >> to;
		
		// 양방향 저장
		edges.push_back({ from, to });
		edges.push_back({ to, from });

		arr[from][to] = arr[to][from] = true;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	// 양방향에 대해 저장하고 있으므로 간선 두배 
	edge *= 2;

	for (int i = 0; i < edge; i++) {
		for (int j = 0; j < edge; j++) {
			// 같은 관계를 두 번 주는 경우는 없기 때문에
			// a, b, c, d 가 모두 다를 경우에 확인 
			// first와 second는 반드시 연결되어 있기 때문에
			// 그 사이 수열만 확인해주면 됨

			// 인접행렬
			// a -> b
			int a = edges[i].first; 
			int b = edges[i].second; 

			// c -> d
			int c = edges[j].first;
			int d = edges[j].second;
			if (a == b || a == c || a == d || b == c || b == d || c == d) {
				continue;
			}

			// 인접 리스트
			// b -> c
			if (!(arr[b][c])) {
				continue;
			}

			// d와 연결된 숫자 중 a,b,c,d 중 어느 것도 아닌 숫자가 있는지 확인
			// d -> e
			for (int e : g[d]) {
				if (a == e || c == e || b == e  || d == e) {
					continue;
				}
				cout << 1 << '\n';
				return 0;
			}
		}
	}
	cout << 0 << '\n';
	return 0;
}