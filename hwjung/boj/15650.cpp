#include<iostream>
using namespace std;

int a[10];
bool c[10];

void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < index; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] || i < a[index-1]) continue;
		c[i] = true;
		a[index] = i;
		go(index + 1, n, m);
		c[i] = false;
	}

}
/* 
int a[10];
void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < index; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = index + 1; i <= n; i++) {
		a[index] = i;
		go(index + 1, n, m);

	}
}

*/
int main() {
	int n, m;
	cin >> n >> m;
	go(0, n, m);
}