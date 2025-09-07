#include<iostream>
#include<vector>
using namespace std;

int go(const vector<int>& day, int index, const vector<int>& cost, int sum) {
	// �ΰ��� ��츦 ��� Ȯ�����־�� ��

	int skip = 0;

	// take�� 0���� �δ� �ͺ��� -1000000���� int min������ �δ� ���� �����ϴ�į
	int take = 0;
	
	if (index >= (int)day.size()) return sum;
	// sum�� �Ű������� �ް��ֱ� �������� ������ ��쿡�� ȣ�� ����
	if (index + day[index] <= (int)day.size())
	{
		take = go(day, index + day[index], cost, sum + cost[index]);
	}
	// skip�� �׻� �����ϱ� ������ if �ܺη�
	skip = go(day, index + 1, cost, sum);

	// �� �� ū ���� ��ȯ
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
