#include<bits/stdc++.h>
using namespace std;

//for finding x such that f(x) is the max/min

// strictly increasing then strictly decreasing function or vice versa
double f(double x) {

}

//switch < for > if it's a stringly decreasing than increasing function
double tsearch() {
	// l and r must contain the function max/min
	double l = 0, r = 1e9, error = 1e-7;
	while (r-l > error) {
		double d = (r - l) / 3;
		double m1 = l + d;
		double m2 = r - d;
		if (f(m1) < f(m2)) {
			l = m1;
		}
		else {
			r = m2;
		}
	}

	return l;
}