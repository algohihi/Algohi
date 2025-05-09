#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int length = prices.size();

    for(int i = 0; i < length-1; i++){
        stack<int> st;
        int pivot = prices[i]; // 기준이될 가격
        for(int j = i+1; j < length-1; j++){
            if(pivot <= prices[j]){
                // 기준보다 크거나 같으면 가격이 유지된 것이므로 push
                st.push(prices[j]);
            }else{
                // 기준보다 떨어졌으면 더이상 확인할 필요가 없으므로 반복문 종료
                break;
            }
        }
        // 
        if(st.size() == 0) answer.push_back(1);
        else answer.push_back(st.size()+1);
    }
    answer.push_back(0); // 마지막 가격은 항상 0초간 가격이 떨어지지 않으므로
    return answer;
}
