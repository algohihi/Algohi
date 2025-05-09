#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> s;

    for (int i = 0; i < prices.size(); i++) {
        while (!s.empty() && prices[i] < prices[s.top()]) {
            int j = s.top();
            s.pop();
            answer[j] = i - j;
        }
        s.push(i);
    }

    while (!s.empty()) {
        int j = s.top();
        s.pop();
        answer[j] = prices.size() - 1 - j;
    }

    return answer;
}