#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool next_Permutation(vector<int>& v);

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i+1;
	}
	bool isNotEnd = true;
	while (isNotEnd) {
		for (int i = 0; i < n; i++)
		{
			cout << v[i] << ' ';
		} 
		cout << '\n';
		isNotEnd = next_Permutation(v);
	}
}
bool next_Permutation(vector<int>& v) {
	int i = (int)v.size() - 1;
	while (i > 0 && v[i - 1] >= v[i])i--;
	if (i <= 0) return false;
	int j = (int)v.size() - 1;
	while (v[i - 1] >= v[j]) j--;
	swap(v[i - 1], v[j]);
	reverse(v.begin() + i, v.end());
	return true;
}