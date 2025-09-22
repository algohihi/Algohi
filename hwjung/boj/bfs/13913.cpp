#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAXNUM 100001
// check
// first : �ش� n���� �ּҵ��޽ð� ���
// second : ���� �ε���(��) ���
vector<pair<int, int>> check(MAXNUM);


int bfs(int n, int end) {
	queue<int> b;
	if (n == end) return 0;
	//if (n > end) {
	//	return n - end;
	//}
	check[n] = { 1,n };
	b.push(n);
	while (!b.empty()) {
		int tmp = b.front();
		b.pop();

		if (tmp == end) return check[tmp].first - 1;

		// --�θ� Ǯ�� ������ n > end�� ���� ó��
		if (n > end) {
			if (tmp - 1 >= 0 && tmp - 1 < MAXNUM && !check[tmp - 1].first) {
				check[tmp - 1].first = check[tmp].first + 1;
				check[tmp - 1].second = tmp;
				b.push(tmp - 1);
			}
		}
		// �� ���� ��� 3���� ��� ��� Ȱ��
		else {
			// -1 �� ���
			if (tmp - 1 >= 0 && tmp - 1 < MAXNUM && !check[tmp - 1].first) {
				check[tmp - 1].first = check[tmp].first + 1;
				check[tmp - 1].second = tmp;
				b.push(tmp - 1);
			}
			// * 2 �� ���
			if (tmp * 2 < MAXNUM && !check[tmp * 2].first) {
				check[tmp * 2].first = check[tmp].first + 1;
				check[tmp * 2].second = tmp;
				b.push(tmp * 2);
			}
			// + 1 �� ���
			if (tmp + 1 < MAXNUM && !check[tmp + 1].first) {
				check[tmp + 1].first = check[tmp].first + 1;
				check[tmp + 1].second = tmp;
				b.push(tmp + 1);
			}
		}
	}
	return check[end].first;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k) << '\n';

	vector<int> result;
	result.push_back(k);
	
	// ������ ���� n�� �� ������ check�� back�� ����Ű��
	// �ε���(second)�� result�� ���
	while (result.back() != n) {
		result.push_back(check[result.back()].second);
	}

	// vector�� ��� �� ������ ���
	while (!result.empty()) {
		cout << result.back() << " ";
		result.pop_back();
	}

	return 0;
}