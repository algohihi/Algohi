// �ۼ��� : ���ؿ�
// �ۼ��� : 250623
// ��������
// - isReverse�� Ȯ���Ͽ� ���� ������ �ڸ� ������ �Ǻ�
// - isReverse�� Ȯ���Ͽ� ��, �� �� ��� ���� �������� �������

#include<iostream>
#include<deque>
#include<vector>
#include <cctype>
#include<string>
using namespace std;

class ACdq {
	deque<int> dq;
	int num; // ������ ����
public:
	// ���� �߻��� ����
	bool isAC = true;
	bool isReverse = false;
	// D
	bool del() {
		if (dq.empty()) {
			cout << "error" << endl;
			acClear();
			isAC = false;
			return false;
		}
		if (isReverse) dq.pop_back();
		else dq.pop_front();
		return true;
	}
	// �� �� �޾ƿ���
	void dqInput() {
		cin >> this->num;
		string s;
		cin >> s;
		isAC = true;

		string numstr = "";
		for (char c : s) {
			if (isdigit(c)) {
				numstr += c;
			}
			else if (!numstr.empty()) {
				dq.push_back(stoi(numstr));
				numstr = "";
			}
		}
		if (!numstr.empty()) {
			dq.push_back(stoi(numstr));
		}
	}
	// �� �� ���
	void dqPrint() {
		cout << "[";
		if (!dq.empty()) {
			if (isReverse) {
				cout << dq[dq.size() - 1];
				for (int i = dq.size() - 2; i >= 0; i--) {
					cout << "," << dq[i];
				}
			}
			else {
				cout << dq[0];
				for (int i = 1; i < dq.size(); i++) {
					cout << "," << dq[i];
				}
			}
		}
		cout << "]" << endl;
		acClear();
	}
	// �� ����
	void acClear() {
		dq.clear();
		num = 0;
	}
	// R
	void rev() {
		isReverse = !isReverse;
	}
};

int main() {
	int n;
	cin >> n;
	while (n-- > 0) {
		string com;
		cin >> com;

		ACdq dq;
		dq.dqInput();

		for (char c : com) {
			if (c == 'R') dq.rev();
			else if (c == 'D') {
				if (!dq.del()) break;
			}
		}
		if (dq.isAC) dq.dqPrint();
	}
}
