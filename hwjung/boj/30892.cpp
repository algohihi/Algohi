/*
* {���� �� �ִ� ���� ��� stack�� ����. max�� top�� ���, pop�ϸ鼭 ��
* �������� ���� max�� T���� ������
* ������ ���� ����
* ���� T�� �������� ���� ������ �ٽ� �ݺ� }
* �� k���� �ݺ��ϰ�, ���� ó���� ���� �� �ִ� ���� �����ϴ� ������ ��ģ �� 
* stack emtpy =1 �̶�� ������ �����ϰ� T�� ����Ѵ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

// �̷��� �ٽ� Ǯ��Կ�...

/* K�� �Դ´� �Ҷ�, ������ ���� ���� ����
int main() {
	long long n, k, t;
	cin >> n >> k >> t;
	long long* a = new long long[n];

	// ������ ũ�⸦ ����
	for (int i = 0; i < n; i++) {
		cin >> *(a + i);
	}

	sort(a, a + n);
	stack<long long> st;
	
	//t���� ū �ֵ� st�� ����, ���� �� �ִ� �ֵ� �� ���� ū �� ��
	for (int i = n - 1; i >= 0; i--) {
		if ( t <= a[i]) {
			st.push(a[i]);
		}
		else {
			t += a[i];
			k--;
			//break;
		}
	}
	

	// pop�������� �ִ밳�� k��°���� �� ���� �� ����
	for (int i = 0; i < k; i++) {
		bool ate = false;
		long long max = 0;
		while (!st.empty() && t > st.top()) {
			max = st.top();
			st.pop();
			ate = true;
		}
		if (ate) t += max;
		else break; // �� �̻� ���� �� �ִ� �� ����
	}
	cout << t;
	delete[] a;
}
*/


// ��� ���� �״�� ����
// �ð� �ʰ�
/*
#include<iostream>
#include<stack>
using namespace std;

int main() {
	long n, k, t;
	cin >> n >> k >> t;
	long long* a = new long long[n];
	
	// ������ ũ�⸦ ����
	for (int i = 0; i < n; i++) {
		cin >> *(a + i);
	}

	stack<long long> st;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			if (t > *(a + j)) {
				st.push(*(a + j));
				//cout << *(a + j) << " ";
			}
		}

		if (st.empty()) break;

		long long max = st.top(); st.pop();
		
		while(!st.empty()) {
			if (max < st.top()) max = st.top();
			st.pop();
		}
		t += max;

		for (int j = 0; j < n; j++) {
			if (*(a + j) == max) { 
				*(a + j) = 0;
				break;
			}
		}
	}
	cout << t;
}
*/