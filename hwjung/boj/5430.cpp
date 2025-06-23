// 시간 초과 발생
// 매번 reverse하여서 시간 초과

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
	}
	// 덱 값 출력
	void dqPrint() {
		cout << "[" << dq[0];
		for (int i = 1; i < dq.size(); i++) {
			cout << "," << dq[i];
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
		// 뒤집기
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