#include<iostream>
using namespace std;
bool c[10]; // �ߺ� ����
int a[10]; 
void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < index; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (c[i]) continue;
		c[i] = true;
		//cout << i << " ";
		// �ٷ� ��� �ÿ��� �ռ� ������ �����⵵ �� -> ���� index ���� ���� ����
		a[index] = i;
		go(index + 1, n, m);
		c[i] = false;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	go(0, n, m);
}