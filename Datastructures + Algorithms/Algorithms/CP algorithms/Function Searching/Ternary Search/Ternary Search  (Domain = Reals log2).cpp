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
		double m = (l + r) / 2;
		if (f(m) < f(m + error/100)) {
			l = m;
		}
		else {
			r = m + error/100;
		}
	}

	return l;
}