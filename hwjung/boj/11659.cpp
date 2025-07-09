#include<iostream>
using namespace std;

// 시간초과 -> 시간초과가 안나기 위해서는 
// 누적합 - 합을 미리 계산해 놓고 빼기해서 처리

int main() {
	// 입출력 시간 최적회
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	// 배열에 처음부터 배열 i까지 더한 값을 저장 
	int* arr = new int[n];
	// 맨 앞 배열은 0으로 세팅
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	// m번 동작
	while (m-- > 0) {
		int x, y;
		cin >> x >> y;
		int sum;
		
		// x가 1인 경우에는 계산 없이 바로 출력 
		if (x == 1) {
			sum = arr[y];
		}
		// x번째 값도 포함해야하기 때문에 x-1
		// 0번째에 0을 넣은 것은 이때 쓰레기값 들어가지 않게 하기 위함
		else {
			sum = arr[y] - arr[x - 1];
		}
		cout << sum << "\n";
	}
}


// 시도 1
/*
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	while (m-- > 0) {
		int x, y;
		int sum = 0;
		cin >> x >> y;
		for (int i = x - 1; i < y; i++) {
			sum += arr[i];
		}
		cout << sum << "\n";
	}
}
*/