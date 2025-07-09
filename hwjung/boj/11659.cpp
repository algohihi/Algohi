#include<iostream>
using namespace std;

// �ð��ʰ� -> �ð��ʰ��� �ȳ��� ���ؼ��� 
// ������ - ���� �̸� ����� ���� �����ؼ� ó��

int main() {
	// ����� �ð� ����ȸ
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	// �迭�� ó������ �迭 i���� ���� ���� ���� 
	int* arr = new int[n];
	// �� �� �迭�� 0���� ����
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	// m�� ����
	while (m-- > 0) {
		int x, y;
		cin >> x >> y;
		int sum;
		
		// x�� 1�� ��쿡�� ��� ���� �ٷ� ��� 
		if (x == 1) {
			sum = arr[y];
		}
		// x��° ���� �����ؾ��ϱ� ������ x-1
		// 0��°�� 0�� ���� ���� �̶� �����Ⱚ ���� �ʰ� �ϱ� ����
		else {
			sum = arr[y] - arr[x - 1];
		}
		cout << sum << "\n";
	}
}


// �õ� 1
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