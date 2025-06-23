// �ð� �ʰ� �߻�
// �Ź� reverse�Ͽ��� �ð� �ʰ�

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

	// D
	bool del() { 
		if (dq.empty()) {
			cout << "error" << endl;
			acClear();
			isAC = false;
			return false;
		}
		dq.pop_front(); 
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
	}
	// �� �� ���
	void dqPrint() {
		cout << "[" << dq[0];
		for (int i = 1; i < dq.size(); i++) {
			cout << "," << dq[i];
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
		// ������
		for (int i = 0; i < dq.size() / 2; i++) {
			/*int tmp = dq[i];
			dq[i] = dq[num - i - 1];
			dq[num - i - 1] = tmp;*/

			swap(dq[i], dq[num - i - 1]);
		}
	}
	//void playAC(int num) {
	//	this->num = num;
	//	string com;
	//	cin >> com;
	//	
	//	for (char c : com) {
	//		if (c == 'R') {
	//			this.Rev();
	//		}
	//	}

	//	this->dqInput();

	//}
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
			if (c == 'R') {
				dq.rev();
			}
			else if (c == 'D') {
				if (!dq.del()) {
					break;
				}
			}
		}
		if (dq.isAC) {
			dq.dqPrint();
		}
	}
}