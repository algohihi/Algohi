#include<iostream>
#include<queue>
using namespace std;
#define MAXNUM 100001

int check[MAXNUM];
queue<int> b;

int bfs(int n, int end) {
	if (n == end) return 0;
	if (n > end) {
		return n - end;
	}
	check[n] = 1;
	b.push(n);
	while (!b.empty()) {
		int tmp = b.front();
		b.pop();
		if (tmp == end) return check[tmp] -1 ;
		if (tmp - 1 >= 0 && tmp - 1 < MAXNUM && !check[tmp - 1]) {
			check[tmp - 1] = check[tmp] + 1;
			b.push(tmp - 1);
		}
		if (tmp * 2 < MAXNUM && tmp != 0 && !check[tmp * 2]) {
			check[tmp * 2] = check[tmp] + 1;
			b.push(tmp * 2);
		}
		if(tmp+1<MAXNUM && !check[tmp+1]){
			check[tmp + 1] = check[tmp] + 1;
			b.push(tmp + 1);
		}
	}
	return check[end];
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k) << '\n';
	return 0;
}