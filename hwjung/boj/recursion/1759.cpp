#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// 최소 한 개의 모음, 최소 두개의 자음
bool passwordRule(string password) {
	int con = 0, vow = 0;
	for (char c : password) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			vow++;
		else
			con++;
	}
	return (con >= 1 && vow >= 2);
}

// 복사비용 절감을 위해 const 키워드로 불변 선언, 참조
void go(int n, const vector<char>& alpha, string password, int i) {
	// index 비교 전 password 먼저 확인해줘야 마지막 알파벳을
	// 반영한 경우에 대해 확인 가능
	if (n == password.length()) {
		if(passwordRule(password))
			cout << password << '\n';
		return;
	}
	if (i >= (int)alpha.size()) return;
	// i번째 알파벳 사용 o
	go(n, alpha, password + alpha[i], i + 1);
	// i번째 알파벳 사용 x
	go(n, alpha, password, i + 1);
}

int main() {
	int n, alNum;
	cin >> n >> alNum;

	vector<char> alpha(alNum);
	for (int i = 0; i < alNum; i++) {
		cin >> alpha[i];
	}

	sort(alpha.begin(), alpha.end());

	string password = "";

	go(n, alpha, password, 0);

}