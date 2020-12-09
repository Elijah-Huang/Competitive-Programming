void EEA(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
	}
	else {
		int x1, y1;
		EEA(b, a % b, x1, y1);
		x = y1;
		y = x1 - y1 * (a / b);
	}

// basically EEA(num u want mod inv of, mod, the inverse, coefficient of mod in bezout's identity)
/*
}
int main() {
	int x;
	int y;
	EEA(85, 13, x, y);
	std::cout << x;
}
*/