#include<iostream>
#include<deque>
#include<queue>
#include<vector>
#define MAX 100001
using namespace std;
vector<int> check(MAX, -1);

int bfs(int n, int end) {
	queue<int> q1, q0;
	q0.push(n);
	//q1.push(n);
	int tmp = 0;
	check[n] = 0;

	// ������ �ݷ� -> ���������� ó���� ��� �ش� ���� ����
	// N = 4, K = 6
	// ����(0 - 1 BFS) : 1   // 4 �� 3(1��) �� 6(��2, 0��)  �� �� 1
	// ���� �ڵ� : 2   // 4 �� 8(0) �� 7(1) �� 6(1)   �� �� 2�� ���� �湮ǥ�õ�
	
	// -> ���� ���� ���� check�� �� �۴ٸ� ������ ���
	while (!q1.empty() || !q0.empty()) {
		while (!q0.empty()) {
			tmp = q0.front();
			if (tmp == end) return check[end];
			q0.pop();
			if (tmp * 2 < MAX && (check[tmp * 2] == -1 || check[tmp *2] > check[tmp])) {
				check[tmp * 2] = check[tmp];
				q0.push(tmp * 2);
			}
			if (tmp + 1 < MAX && (check[tmp + 1] == -1 || check[tmp + 1]  > check[tmp] + 1)) {
				check[tmp + 1 ] = check[tmp] + 1;
				q1.push(tmp + 1);
			}
			if (tmp - 1 >= 0 && (check[tmp - 1] == -1 || check[tmp - 1] > check[tmp] + 1)) {
				check[tmp - 1] = check[tmp] + 1;
				q1.push(tmp - 1);
			}
		}
		while (!q1.empty()) {
			tmp = q1.front();
			if (tmp == end) return check[end];
			q1.pop();
			if (tmp * 2 < MAX && (check[tmp * 2] == -1 || check[tmp * 2] > check[tmp])) {
				check[tmp * 2] = check[tmp];
				q0.push(tmp * 2);
			}
			if (tmp + 1 < MAX && (check[tmp + 1] == -1 || check[tmp + 1] > check[tmp] + 1)) {
				check[tmp + 1] = check[tmp] + 1;
				q1.push(tmp + 1);
			}
			if (tmp - 1 >= 0 && (check[tmp - 1] == -1 || check[tmp - 1] > check[tmp] + 1)) {
				check[tmp - 1] = check[tmp] + 1;
				q1.push(tmp - 1);
			}
		}

	}
	return check[end];
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k)<< '\n';

}