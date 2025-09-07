#include<iostream>
#include<vector>
using namespace std;

int go(const vector<int>& day, int index, const vector<int>& cost, int sum) {
	// 두가지 경우를 모두 확인해주어야 함

	int skip = 0;

	// take를 0으로 두는 것보다 -1000000같은 int min값으로 두는 것이 안전하다캄
	int take = 0;
	
	if (index >= (int)day.size()) return sum;
	// sum을 매개변수로 받고있기 때문에만 가능한 경우에만 호출 진행
	if (index + day[index] <= (int)day.size())
	{
		take = go(day, index + day[index], cost, sum + cost[index]);
	}
	// skip은 항상 가능하기 때문에 if 외부로
	skip = go(day, index + 1, cost, sum);

	// 둘 중 큰 값을 반환
	return max(skip,take);
}

int main() {
	int n;
	cin >> n;
	vector<int> day(n), cost(n);

	for (int i = 0; i < n; i++) {
		cin >> day[i] >> cost[i];
	}
	cout << go(day, 0, cost, 0) << '\n';
}
