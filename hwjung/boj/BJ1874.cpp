#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];

	// 수열 입력
	for (int i = 0; i < n; i++) {
		cin >> *(arr + i);
	}

	stack<int> st;
	// 큐를 이용하면 출력이 더 편할 것 같아서 써봤음
	queue<char> q;

	int idx = 0;
	int j;
	//스택에 값 넣기
	for (j = 1; j <= n; j++) {
		if (!st.empty() && arr[idx] == st.top()) {
			st.pop();
			q.push('-');
			idx++;
			//값을 뛰어넘지 않도록, 같은 정수 두번 나오는 문제 발생
			j--;
		}
		else {
			st.push(j);
			q.push('+');
		}
	}
	
	// 스택에 남아있는 수와 배열 값을 비교
	while (idx <= n && !st.empty()) {
		if (arr[idx] == st.top()) {
			st.pop();
			q.push('-');
			idx++;
		}
		else {
			break;
		}
	}

	if (!st.empty()) cout << "NO";
	else {
		while (!q.empty()) {
			cout << q.front() << "\n";
			q.pop();
		}
	}
}

