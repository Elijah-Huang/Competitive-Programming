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
		int m = (l + r) / 2;
		if (f(m) < f(m + 1)) {
			l = m + 1;
		}
		else {
			r = m;
		}
	}

	return l;
}