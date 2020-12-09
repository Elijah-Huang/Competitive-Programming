int n, m;
string s1(n,' '), s2(m,' ');
vector<int> pf(m);
for (int i = 1; i < m; i++) {
	int j = pf[i - 1];
	while (j > 0 and s2[i] != s2[j]) {
		j = pf[j - 1];
	}
	pf[i] = j + (s2[i] == s2[j])
}
int j = 0;
bool found = false;
for (int i = 0; i < n; i++) {
	while (j > 0 and s1[i] != s2[j]) {
		j = pf[j - 1];
	}
	j += (s1[i] == s2[j]);
	if (j == m) {
		found = true;
		break;
	}
}