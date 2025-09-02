#include<iostream>
using namespace std;

int main() {


	int a[3];
	cin >> a[0] >> a[1] >> a[2];

	// 规过 1
	int cnt = 1;
	/*
	int e = 1, s = 1, m = 1;
	while (1) {
		if (e == a[0] && s == a[1] && m == a[2]) {
			cout << cnt << '\n';
			return 0;
		}
		cnt++;
		e++;
		s++;
		m++;
		if (e > 15) e = 1;
		if (s > 28) s = 1;
		if (m > 19) m = 1;
	}
	*/

	// 规过 2 
	for (int i = 0; i < 3; i++) {
		a[i] -= 1;
	}
	cnt = 1;
	while (1) {
		if (cnt % 15 == a[0] && cnt % 28 == a[1] && cnt % 19 == a[2]) {
			cout << cnt + 1 << '\n';
			return 0;
		}
		cnt++;
	}
}