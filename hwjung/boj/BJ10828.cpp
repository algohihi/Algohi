#include <iostream>

int main()
{
	int n = 0, col = 0;
	std::string command;
	int stack[10000] = { 0 };
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> command;
		if (command == "push") {
			std::cin >> stack[col++];
		}
		else if (command == "pop") {
			if (col == 0) {
				std::cout << -1 << '\n';
			}
			else {
				std::cout <<stack[--col] << '\n';
				stack[col] = 0;
			}
		}
		else if (command == "size") {
			std::cout << col << '\n';
		}
		else if (command == "empty") {
			if (col == 0) {
				std::cout << 1 << '\n';
			}
			else {
				std::cout << 0 << '\n';
			}
		}
		else if (command == "top") {
			if (col == 0) {
				std::cout << -1 << '\n';
			}
			else {
				std::cout << stack[col - 1] << '\n';
			}
		}
	}
}



//unorderd_map라는 것도 있다

//test
