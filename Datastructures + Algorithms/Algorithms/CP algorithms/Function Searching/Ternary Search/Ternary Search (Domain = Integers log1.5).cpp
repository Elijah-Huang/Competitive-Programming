#include<bits/stdc++.h>
using namespace std;

//for finding x such that f(x) is the max/min

// strictly increasing then strictly decreasing function or vice versa
int f(int x) {

}

//switch < for > if it's a stringly decreasing than increasing function
int tsearch() {
	// l and r must contain the function max/min
	int l = 0, r = 1e9;
	while (l != r) {
		int d = (r - l) / 3;
		int m1 = l + d;
		int m2 = r - d;
		if (f(m1) < f(m2)) {
			l = m1 + 1;
		}
		else {
			r = m2 - 1;
		}
	}

	return l;
}