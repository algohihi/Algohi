#include <iostream>

//비주얼 스튜디오에는 GCD함수가 없어 직접 작성
int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}

int main()
{
	int a1, a2, b1, b2; // a 분모 b 분자
	int denominator, numerator;
	std::cin >> b1 >> a1 >> b2 >> a2;
		
	denominator = a1 * a2;
	numerator = b1 * a2 + b2 * a1;

	int g = GCD(denominator, numerator);

	std::cout << numerator / g << " " << denominator / g;
	return 0;
}

/* 백준 GCC컴파일러에는 gcd 존재, 다음과 같이 작성하여도 정답처리
#include <iostream>
#include <numeric>

int main()
{
	int a1, a2, b1, b2; // a 분모 b 분자
	int denominator, numerator;
	std::cin >> b1 >> a1 >> b2 >> a2;

	denominator = a1 * a2;
	numerator = b1 * a2 + b2 * a1;

	int g = std::gcd(denominator, numerator);

	std::cout << numerator / g << " " << denominator / g;
	return 0;
}
*/


// 최대공약수 구하기 : 유클리드 호제법
/*
48 = 18 × 2 + 12
→ 이 식에서 공약수 d가 18을 나눌 수 있다면,
→ 당연히 18 × 2도 나눌 수 있고,
→ 그렇다면 48 = (18 × 2) + 12도 나눌 수 있으려면,
→ 결국 d는 12도 나눌 수 있어야만 함

즉: d | 48 이고 d | 18 이라면, d | 12도 되어야 논리적으로 성립
*/


/* 방법 2 오답
*	>> 약분 기준이 아님
	int a1, a2, b1, b2; // a 분모 b 분자
	int numerator, denominator;
	std::cin >> b1 >> a1 >> b2 >> a2;

	fraction = a1 * a2;
	denominator = b1 * a2 + b2 * a1;

	// 약분
	int n = denominator / numerator;
	if (n == 0) {
		numerator = 1;
		denominator = denominator / numerator;
	}
	else {
		if ((denominator % n == 0) || (numerator % n == 0)) {
			denominator = denominator / n;
			numerator = numerator / n;
		}
	}

	std::cout << numerator << " " << denominator;
	return 0;

*/