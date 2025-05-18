#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	//n번 반복
	for (int i = 0; i < n; i++) {
		stack<char> st1, st2;
		string s = "";
		cin >> s;

		for (char c : s) {
			// < 일 경우  st1이 비어있지 않을 경우 st1의 top을 st2에 push하고 st1을 pop한다
			if (c == '<') {
				if (!(st1.empty())) {
					st2.push(st1.top());
					st1.pop();
				}
			}
			// > 일 경우 st2가 비어있지 않을 경우 st2의 top을 st1에 push하고 st2를 pop한다
			else if (c == '>') {
				if (!(st2.empty())) {
					st1.push(st2.top());
					st2.pop();
				}
			}
			// - 일 경우  st1이 비어있지 않을 경우 st1을 pop한다
			else if (c == '-') {
				if (!(st1.empty())) {
					st1.pop();
				}
			}
			//이외 문자는 st1에 push한다
			else {
				st1.push(c);
			}
		}

		//입력이 모두 끝나고나면 st1을 empty가 true가 될때까지 top을 st2에 push한다
		while (!(st1.empty())) {
			st2.push(st1.top());
			st1.pop();
		}

		while (!(st2.empty())) {
			cout << st2.top();
			st2.pop();
		}
		cout << '\n';
	}
}
