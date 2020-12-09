#include<iostream>
void func(int a[10][10]) {
	sizeof(*a);
	sizeof(a[8]);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << a[i][j];
		}
		std::cout << '\n';
	}
}
int main() {
	int a[10][10]{};
	for (auto i = a; i < a + sizeof(a) / sizeof(a[0]); i++) {
		for (auto j : *i) {
			std::cout << j;
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	func(a);
}