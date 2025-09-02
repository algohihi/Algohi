#include<iostream>
using namespace std;

int a[10];
void go(int index, int n, int m, int start) {
	if (index == m) {
		for (int i = 0; i < index; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++) {
		a[index] = i;
		go(index + 1, n, m, i);
	}

}
int main() {
	int n, m;
	cin >> n >> m;
	go(0, n, m, 1);
}