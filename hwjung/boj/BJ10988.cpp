#include <iostream>

int main()
{
	int n;
	bool isPalindrome = 1;
	std::string str;
	std::cin >> str;

	n = str.length();

	for (int i = 0; i < n / 2; i++) {
		if (str[i] != str[n - i - 1]) {
			isPalindrome = 0;
			break;
		}
	}

	std::cout << isPalindrome << '\n';
	return 0;

}

// 초기 선언 후 if를 충족하지 않으면 팰린드롬