#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>  // setprecision 사용을 위해 필요

using namespace std;

bool isOperator(char c);
double calculation(double n1, double n2, char c);

int main(){
    vector<double> v;    // 피연산자 받을 벡터
    int n = 0;          // 피연산자 개수
    int len = 0;        // 연산식 길이
    string str;         // 연산식
    stack<double> st;

    // 피연산자 개수, 연산식 입력받기
    cin >> n;
    cin >> str;
    len = str.length();

    // 피연산자 입력받기
    for(int i = 0; i < n; i++){
        double value;
        cin >> value;
        v.push_back(value);
    }

    // 계산하기
    for(int i = 0; i < len; i++){
        if(isOperator(str[i])){
            double n1 = st.top();
            st.pop();

            double n2 = st.top();
            st.pop();

            st.push(calculation(n1, n2, str[i]));
            continue;
        }
        int idx = str[i] - 'A'; // A인 경우 idx=0, B인 경우 1
        st.push(v[idx]);
    }

    // 소수점 이하 2자리까지 출력하는 방법 
    cout << fixed << setprecision(2) << st.top() << endl;
    // fixed: 소수점 이하를 고정
    // setprecision(n) 소수점 이하 n까지 출력 
    return 0;
}

bool isOperator(char c){
    if( c == '*' || c == '/' || c == '-' || c == '+' ) return true;
    return false;
}

double calculation(double n1, double n2, char c){
    if(c == '*'){
        return n1 * n2;
    }
    if(c == '/'){
        return n2 / n1; // 순서에 유의
    }
    if (c == '-'){
        return n2 - n1; // 순서에 유의
    }
    if (c == '+'){
        return n1 + n2;
    }
    return 0;
}



/*
후위표기식2 의사 코드
1. 먼저 뭐부터해야할깡
2. 피연산자의 개수를 입력 받는다
3. 후위표기식을 입력 받는다(string)
4. 피연산자에 해당하는 값도 입력 받는다
    1. 알파벳에 맞는 값으로 갈아끼운다
5. stack에 쌓아보자(0-length)
    1. isdigit 이면 stack에 넣고
    2. 아니면 pop() *2
        1. 연산자를 확인해서 연산하기(char -> int)
        2. 연산 결과를 다시 stack에 넣어주기
6. stack.top() = 결과
7. 출력 scanf(“%.2f”, stack.top());
*/

/*
float로 해서 틀림 -> double로 하니까 맞음
[이유] double과 float의 정확도 차이

float은 32비트(약 7자리 정도 정확도)
double은 64비트(약 15자리 정도 정확도)

간단히 말하면 float으로 계산하면 작은 오차가 누적되어 정답과 달라질 수 있다.
double은 더 정밀해서 오차가 줄고, 문제 통과 가능성이 높아진다.
*/
