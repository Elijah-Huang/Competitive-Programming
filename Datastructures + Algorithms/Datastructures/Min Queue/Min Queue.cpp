#include<bits/stdc++.h>
using namespace std;

// queue that you can find the min with in O(1) amortized, swap > with < for max queue
template<class T>
struct min_queue {
	queue<T> q;
	deque<T> dq;

	int size() {
		return q.size();
	}

	void push(T a) {
		if (q.empty()) {
			q.push(a);
			dq.push_back(a);
		}
		else {
			q.push(a);
			while (!dq.empty() and dq.back() > a) {
				dq.pop_back();
			}
			dq.push_back(a);
		}
	}

	void pop() {
		if (q.front() == dq.front()) {
			dq.pop_front();
		}
		q.pop();
	}

	T getmin() {
		return dq.front();
	}
};