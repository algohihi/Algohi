#include<iostream>
#include<vector>
#define mod 1000000000
using namespace std;
long long d[201][201];
long long d2[201];

int main() {
	int n, k;
	cin >> n >> k;

	if (n > 200 || k > 200) return 0;

	for (int i = 0; i <= k; i++) {
		d[i][0] = 1;
	}
	
	d2[0] = 1;

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = d[i][j - 1] + d[i - 1][j];
			d[i][j] %= mod;
		}
	}
	

	// 왜 k가 앞 반복문에 와야하는 가? 
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			d2[j] += d2[j - 1];
			d2[j] %= mod;
		}
	}

	//cout << d[k][n] << '\n';
	cout << d2[n] << '\n';
}