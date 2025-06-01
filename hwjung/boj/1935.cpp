#include<iostream>
#include<stack>
#include<map>
using namespace std;
double Operation(char c, double a, double b);

int main() {
	// �ǿ����� ���� �Է�
	// ����ǥ��� �Է�
	int n;
	string s;
	cin >> n;
	cin >> s;

	/* �� ��� c�� �����ؼ� ó���ϱ� ������ c�� ���� �ٲ� �� ����
	* ���ʿ� ���� ���ĺ��� ���� ó���� ���� ���� ����
	* -> ���ĺ� ���� ó���� �� �ʿ䰡 ����
	
	for (char c:s) {
		if (c >= 'A' && c <= 'Z') cin >> c;
	}
	*/

	//������ �迭 a�� ���ĺ� �� ����
	double* arr = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> *(arr + i);
	}

	/* ������ ���� ���� �Ӵ��� ���ڿ��� ���̰� ���� �� �ִ�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[j] == 'A' + i) s.replace(j, 1, *(a + i));
		}
	}
	*/

	// map<key, value> ������ Ű-�� �� ����
	map<char, double> m;
	for (int i = 0; i < n; i++) {
		m['A' + i] = *(arr + i);
	}

	stack<double> st;
	
	for (char c : s) {
		//map�� �ִ� ���� ������ ���ÿ� ����
		//stack���� ���ڸ� ����, map�� ġȯ�� ���� ó���� st.push(m[c])�� �Ѵٰ�
		//map�� ����ü�� ���� ���� �ƴ� m[c]�� ��ȯ�ϴ� double���� ����ȴ�
		if (isalpha(c)) st.push((m[c]));
		else {
			double a, b;
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			st.push(Operation(c, b, a));
		}
	} 
	// �Ǽ��� ���� �ڸ��� ����
	cout << fixed;
	cout.precision(2);
	cout << st.top();

	delete [] arr;
}

double Operation(char c, double a, double b) {
	switch (c) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
}