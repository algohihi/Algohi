#include <iostream>
#include <string>
#include <deque> // deque 자료구조

using namespace std;
// T  0 < t <=100  테스트 횟수
// P 1<= p <= 100,000 명령어 (R/D)
// N 0<= n <=  100,000 입력받을 배열

int main()
{
    int t; // 테스트 횟수
    cin >> t;
    if (t > 100)
        return;

    while (t--) // t번 반복
    {

        string p; // 명령어 문자열

        int n;         // 배열 크기
        string arrStr; // 배열 문자열 "[ 1,2,3,4]"  이런식 > 문자열로 받아서 정수로 바꾸기

        cin >> p >> n >> arrStr; // 입력받기

        // 비어있는 int deque  선언
        deque<int> dq;

        // 배열 파싱 (문자열에서 >>  숫자(정수) 추출)
        if (n > 0)
        {                    // 배열이 비어있지 않은 경우 > 실행
            string num = ""; // 숫자를 임시 저장할 문자열 >> 초기화

            // 문자열 한 글자씩 확인
            for (int i = 1; i < arrStr.length() - 1; i++)
            {                         // 앞"[", 뒤 "]" 제외 > ([1]~[len-1])
                if (arrStr[i] == ',') // 쉼표 만나면
                {
                    dq.push_back(stoi(num)); // 숫자 변환 > deque 추가
                    num = "";                // 숫자 문자열 초기화
                }
                else // 배열 비어있으면 > 실행 x
                {
                    num += arrStr[i]; // 숫자 문자 추가
                }
            }

            if (!num.empty()) // 맨뒤는 쉼표없이 ']' 후 for문 종료되므로
            {
                dq.push_back(stoi(num)); // 마지막 > 숫자로 처리
            }
        }

        bool reversed = false; // 뒤집힌 상태 여부
        bool error = false;    // 에러발생여부

        // R/D 명령어 하나씩 처리
        for (int j = 0; j < p.length(); j++)
        { // for(char command : p)로 가능하다함
            char command = p[j];

            if (command == 'R')
            {
                reversed = !reversed; // "뒤집은 상태"
            }
            else if (command == 'D')
            {
                if (dq.empty())
                {                 // deque 비어있으면
                    error = true; // 에러발생
                    break;        // 반복문 탈출
                }
            }

            if (reversed) // 뒤집힌 상태
            {
                dq.pop_back(); // 뒤에서 제거
            }
            else
            {                   // 정상 상태
                dq.pop_front(); // 앞에서 제거
            }
        }

        // 결과 출력
        if (error)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << "[";

            if (!dq.empty()) // deque 비어있지 않으면
            {
                if (reversed)
                { // 뒤집힌 상태면 뒤에서 부터
                    for (int i = dq.size() - 1; i >= 0; i--)
                    {
                        cout << dq[i];
                        if (i > 0)
                            cout << ","; // 마지막 아니면 쉼표
                    }
                }
                else
                { // 정상 상태면
                    for (int i = 0; i < dq.size(); i++)
                    {
                        cout << dq[i];
                        if (i < dq.size() - 1)
                            cout << ",";
                    }
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}