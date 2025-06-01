#include<iostream>
#include<stack>
#include<map>
using namespace std;
double Operation(char c, double a, double b);

int main() {
	// 피연산자 개수 입력
	// 후위표기식 입력
	int n;
	string s;
	cin >> n;
	cin >> s;

	/* 이 경우 c를 복제해서 처리하기 때문에 c의 값을 바꿀 수 없음
	* 애초에 같은 알파벳에 대한 처리를 전혀 하지 못함
	* -> 알파벳 별로 처리해 줄 필요가 있음
	
	for (char c:s) {
		if (c >= 'A' && c <= 'Z') cin >> c;
	}
	*/

	//포인터 배열 a에 알파벳 값 저장
	double* arr = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> *(arr + i);
	}

	/* 형식이 옳지 못할 뿐더러 문자열의 길이가 변할 수 있다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[j] == 'A' + i) s.replace(j, 1, *(a + i));
		}
	}
	*/

	// map<key, value> 형태의 키-값 쌍 저장
	map<char, double> m;
	for (int i = 0; i < n; i++) {
		m['A' + i] = *(arr + i);
	}

	stack<double> st;
	
	for (char c : s) {
		//map에 있는 값을 꺼내어 스택에 저장
		//stack에는 숫자만 저장, map은 치환을 위한 처리로 st.push(m[c])를 한다고
		//map이 그자체로 들어가는 것이 아닌 m[c]가 반환하는 double값이 저장된다
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
	// 실수에 대한 자리수 지정
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