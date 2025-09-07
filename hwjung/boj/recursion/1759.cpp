#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// �ּ� �� ���� ����, �ּ� �ΰ��� ����
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

// ������ ������ ���� const Ű����� �Һ� ����, ����
void go(int n, const vector<char>& alpha, string password, int i) {
	// index �� �� password ���� Ȯ������� ������ ���ĺ���
	// �ݿ��� ��쿡 ���� Ȯ�� ����
	if (n == password.length()) {
		if(passwordRule(password))
			cout << password << '\n';
		return;
	}
	if (i >= (int)alpha.size()) return;
	// i��° ���ĺ� ��� o
	go(n, alpha, password + alpha[i], i + 1);
	// i��° ���ĺ� ��� x
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