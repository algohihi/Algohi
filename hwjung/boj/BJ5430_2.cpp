// 작성자 : 정해원
// 작성일 : 250623
// 수정사항
// - isReverse를 확인하여 앞을 지울지 뒤를 지울지 판별
// - isReverse를 확인하여 앞, 뒤 중 어느 쪽을 기준으로 출력할지

#include<iostream>
#include<deque>
#include<vector>
#include <cctype>
#include<string>
using namespace std;

class ACdq {
	deque<int> dq;
	int num; // 원소의 개수
public:
	// 에러 발생시 종료
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
	// 덱 값 받아오기
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
	// 덱 값 출력
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
	// 덱 비우기
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
