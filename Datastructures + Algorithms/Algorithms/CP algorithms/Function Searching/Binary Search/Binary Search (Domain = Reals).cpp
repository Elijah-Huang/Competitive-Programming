#include<bits/stdc++.h>
using namespace std;

//finds the first or last x such that f(x) = 1

// monotonic boolean function
bool f(double x) {

}

// this is for 000111
int bsearch1() {
	//l and r contain the first/last x
	double l = 0, r = 1e9, error = 1e-7;
	while (r-l > error) {
		int m = (l + r) / 2;
		if (f(m)) {
			r = m;
		}
		else {
			l = m;
		}
	}

	return l;
}

//this is for 111000;
int bsearch2() {
	//l and r contain the first/last x
	double l = 0, r = 1e9, error = 1e-7;
	while (r-l > error) {
		int m = (l + r) / 2;
		if (f(m)) {
			l = m;
		}
		else {
			r = m;
		}
	}

	return l;
}