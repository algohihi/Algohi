#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> d(n + 1,0);
	vector<int> s(n + 1, 0);

	d[0] = 1;
	s[0] = 1;
	for (int i = 2; i <= n; i += 2) {
		d[i] = d[i - 2] * 3;
		if (i != 2) {
			d[i] += s[i - 4] * 2;
		}
		s[i] = s[i - 2] + d[i];

	}
	cout << d[n] << '\n';
}