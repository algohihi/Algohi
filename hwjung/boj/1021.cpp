#include<iostream>
#include<deque>
using namespace std;

class Rdeque {
	deque<int> dq;
	int num;
	int count = 0;
public:
	Rdeque(int num) {
		this->num = num;
		for (int i = 1; i <= num; i++) {
			dq.push_back(i);
		}
	}
	void ftoe(){
		dq.push_back(dq.front());
		dq.pop_front();
		count++;
	}
	void etof() {
		dq.push_front(dq.back());
		dq.pop_back();
		count++;
	}
	void findNum(int a) {
		// 인덱스 먼저 확인
		int idx;
		bool forb = false;
		for (int i = 0; i < dq.size(); i++) {
			if (a == dq[i]) {
				idx = i;
				break;
			}
		}

		if (idx <= dq.size() / 2) forb = true;

		while (1) {
			if (dq.front() == a) {
				dq.pop_front();
				return;
			}

			if (forb) {
				ftoe();
			}
			else {
				etof();
			}
		}
	}
	int getCount() { return count; }
};

int main() {
	int n;
	cin >> n;
	Rdeque q(n);

	int m;
	cin >> m;
	while (m > 0) {
		int a;
		cin >> a;
		q.findNum(a);
		m--;
	}
	cout << q.getCount();

}