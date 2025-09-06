#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool next_Permutation(vector<int> &v);
int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	bool ans = next_Permutation(v);
	if (!ans) {
		cout << -1;
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
	}
}

bool next_Permutation(vector<int> &v) {
	// v.size()�� size_t���� ��ȯ�Ѵٰ� ��, ���������� ����ȯ
	int i = (int)v.size() - 1;
	while (i > 0 && v[i - 1] >= v[i]) i--;
	if (i <= 0) return false; // �� ������ ����
	int j=(int)v.size() - 1;

	// ������ ���� �񱳰� �ε��� ���� ����
	while (v[j]<= v[i - 1]) j--;
	swap(v[i-1],v[j]);

	// i���� ������ ������
	reverse(v.begin() + i, v.end());
	return true; // ���� �Ϸ�
}