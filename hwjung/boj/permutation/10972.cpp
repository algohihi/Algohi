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
	// v.size()는 size_t형을 반환한다고 함, 에러방지용 형변환
	int i = (int)v.size() - 1;
	while (i > 0 && v[i - 1] >= v[i]) i--;
	if (i <= 0) return false; // 맨 마지막 순열
	int j=(int)v.size() - 1;

	// 끝에서 부터 비교가 인덱스 접근 안전
	while (v[j]<= v[i - 1]) j--;
	swap(v[i-1],v[j]);

	// i부터 끝까지 뒤집기
	reverse(v.begin() + i, v.end());
	return true; // 정렬 완료
}