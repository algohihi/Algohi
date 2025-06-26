#include<iostream>
#include<deque>
using namespace std;

class MinArr {
	deque<int> dq;
	int* min;
	int n;
	int l;
public:
	MinArr(int n, int l) {
		this->n = n;
		this->l = l;
		min = new int[n];
	}
	void findMin(int* num) {
		for (int i = 0; i < n; i++) {
			// ���� ����� ���� �ٷ� push
			if (dq.empty()) {
				dq.emplace_front(i);
			}
			// �� �տ� ������ ���� ���� ���� ���
			// ���� ��� ���� ���� �� �߰�
			else if (num[dq.front()] >= num[i]) {
				dq.clear();
				dq.push_front(i);
			}
			// �ڿ�������, �ڱ⺸�� ū ���� �տ� ���������� pop
			else {
				for (int j = dq.size() - 1; j >= 0; j--) {
					if (num[i] <= num[dq[j]]) {
						dq.pop_back();
					}
					else {
						dq.push_back(i);
						break;
					}
				}
			}

			// ������ ���� �� �� ����
			int range = i - l + 1;

			if (!dq.empty() && dq.front() < range){
				dq.pop_front();
			}
			cout << num[dq.front()] << " ";
		}
	}

};


int main() {
	int n, l;
	cin >> n >> l;

	int* num = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> *(num + i);
	}
	MinArr m(n, l);
	m.findMin(num);
	
	delete[] num;
	return 0;
}



// �׳� Ǯ���
// �ð��ʰ�
/*
#include<iostream>
using namespace std;

class MinArr {
	int n;
	int l;
	int* min;
public:
	MinArr(int n, int l) { this->n = n; this->l = l; this->min = new int[n]; }
	void findMin(int* num) {
		for (int i = 0; i < n; i++) {
			int range = i - l + 1;
			if (range < 0) range = 0;
			min[i] = num[range];
			for (int j = range; j <= i; j++) {
				if (min[i] > num[j]) min[i] = num[j];
			}
		}

		for (int i = 0; i < n; i++) {
			cout << min[i] << " ";
		}
	}

};


int main() {

	cin >> n >> l;

	int *num =  new int[n];
	int n, l;
	for (int i = 0; i < n; i++) {
		cin >> *(num + i);
	}
	MinArr m(n, l);
	m.findMin(num);
}
*/