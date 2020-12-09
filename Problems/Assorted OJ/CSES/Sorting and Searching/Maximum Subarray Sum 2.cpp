#include<bits/stdc++.h>
using namespace std;

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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, a, b; cin >> n >> a >> b;
	min_queue<long long> mq;
	vector<int> x(n + 1);
	vector<long long> psum(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}

	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + x[i];
	}
	
	long long mx = -(1ll<<50);
	for (int i = 0; i <= n-a; i++) {
		if (mq.size() == b - a + 1) {
			mq.pop();
			mq.push(psum[i]);
		}
		else {
			mq.push(psum[i]);
		}
		mx = max(mx, psum[i + a] - mq.getmin());
	}

	cout << mx;
}