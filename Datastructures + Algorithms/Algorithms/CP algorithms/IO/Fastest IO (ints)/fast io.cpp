#include<bits/stdc++.h>
using namespace std;
#define reg register
#define eps 1e-6
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000], * p1 = buf, * p2 = buf;


// HERE
inline int read(void) {
	reg bool f = false;
	reg char ch = getchar();
	reg int res = 0;
	while (ch < '0' || '9' < ch)f |= (ch == '-'), ch = getchar();
	while ('0' <= ch && ch <= '9')res = 10 * res + ch - '0', ch = getchar();
	return f ? -res : res;
}




const int MAXN = 100000 + 5;

inline void Read(void);

struct Node {
	double x, y;
	inline Node(reg double x = 0, reg double y = 0) :x(x), y(y) {
		return;
	}
	inline void Read(void) {
		x = read(), y = read();
		return;
	}
	inline bool operator==(const Node& a) {
		return fabs(x - a.x) < eps && fabs(y - a.y) < eps;
	}
};

int n;
Node a[MAXN];

inline void Read(void) {
	n = read();
	for (reg int i = 1; i <= n; ++i)
		a[i].Read();
	return;
}

inline Node GetMid(const Node& a, const Node& b) {
	return Node((a.x + b.x) * 0.5, (a.y + b.y) * 0.5);
}

