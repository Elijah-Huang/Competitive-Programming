long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}
long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}


long long gcd(long long a, long long b) {
	while (b) {
		a, b = b, a % b;
	}
	return a;
}
long long gcd(long long a, long long b) {
	while (b) {
		long long a1 = a;
		a = b;
		b = a1 % b;
	}
	return a;
}
long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
