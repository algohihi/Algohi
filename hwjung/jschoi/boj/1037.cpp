#include <cstdio>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

void sort(vector<int> &score);

int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> score(n);

    // 입력
    for(int i = 0; i < n; i++) cin >> score[i];
    // 정렬
    sort(score.begin(), score.end(), greater<int>());
    // 출력
    cout << score[k-1];
}


/*
1.정렬 정리
오름차순    │ sort(v.begin(), v.end());                     | 시작위치, 끝위치 
내림차순    │ sort(v.begin(), v.end(), greater<int>());     | 시작위치, 끝위치, greater<int>()
    1-1.greater<int>()
        greater<int>()는 <functional> 헤더에 정의
        두 값을 비교해서 "왼쪽 > 오른쪽"이면 true를 반환
        greater<int>()는 [] (int a, int b) { return a > b; } 람다식과 똑같은 역할을 해!
        ```c++
        std::greater<int> comp;
        comp(3, 2); // true → 3 > 2
        comp(2, 3); // false → 2 > 3
        ```
    1-2. 람다식: 이름 없는 함수(익명 함수)를 만들 때 쓰는 문법
        sort 같은 STL 함수에 직접 넣어서 정렬 기준 등으로 자주 사용
        [캡처](매개변수) { 실행코드 } 형식으로 사용
        (예) auto add = [](int a, int b) -> int { return a + b; };
            *캡처: 람다식에서 외부 변수를 람다 내부로 가져오는 기능. 대괄호를 사용한다.

    1-3. STL: Standard Template Library의 약자. 여러 자료 구조, 함수, 알고리즘 등을 쓰기 쉽게 정형화해둔 라이브러리

        
2. 벡터 사용법
vector<자료형> 변수명	
vector<자료형> 변수명(숫자)	숫자만큼 벡터 생성 후 0으로 초기화
vector<자료형> 변수명(숫자, 변수1)	숫자만큼 벡터 생성 후 변수1으로 모든 원소 초기화
vector<자료형> 변수명={변수1,변수2,변수3,...}	벡터 생성 후 오른쪽 변수 값으로 초기화
vector<자료형> 변수명[]={{변수1,변수2},{변수3,변수4},...}	벡터 배열(2차원 벡터) 선언 및 초기화(열은 고정, 행은 가변)
vector<vector <자료형>> 변수명	2차원 벡터 생성(열과 행 모두 가변)
vector<자료형>변수명.assign(범위, 초기화할 값)	벡터의 범위 내에서 해당 값으로 초기화
*/