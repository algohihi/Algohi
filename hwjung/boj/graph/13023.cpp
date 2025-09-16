#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool arr[2000][2000]; // ������� 
vector<int> g[2000]; // ��������Ʈ

int main() {
	int node, edge;
	cin >> node >> edge;
	
	vector<pair<int, int>> edges; // ���� ����Ʈ
	for (int i = 0; i < edge; i++) {
		int from, to;
		cin >> from >> to;
		
		// ����� ����
		edges.push_back({ from, to });
		edges.push_back({ to, from });

		arr[from][to] = arr[to][from] = true;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	// ����⿡ ���� �����ϰ� �����Ƿ� ���� �ι� 
	edge *= 2;

	for (int i = 0; i < edge; i++) {
		for (int j = 0; j < edge; j++) {
			// ���� ���踦 �� �� �ִ� ���� ���� ������
			// a, b, c, d �� ��� �ٸ� ��쿡 Ȯ�� 
			// first�� second�� �ݵ�� ����Ǿ� �ֱ� ������
			// �� ���� ������ Ȯ�����ָ� ��

			// �������
			// a -> b
			int a = edges[i].first; 
			int b = edges[i].second; 

			// c -> d
			int c = edges[j].first;
			int d = edges[j].second;
			if (a == b || a == c || a == d || b == c || b == d || c == d) {
				continue;
			}

			// ���� ����Ʈ
			// b -> c
			if (!(arr[b][c])) {
				continue;
			}

			// d�� ����� ���� �� a,b,c,d �� ��� �͵� �ƴ� ���ڰ� �ִ��� Ȯ��
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