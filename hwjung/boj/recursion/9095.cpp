#include <iostream>
using namespace std;

int go(int sum, int goal) {
	if (sum > goal)return 0;
	if (sum == goal) return 1;
	
	int now = 0;
	for (int i = 1; i <= 3; i++) {
		now += go(sum + i, goal);
	}
	return now;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		cout << go(0, a) << '\n';
	}

}