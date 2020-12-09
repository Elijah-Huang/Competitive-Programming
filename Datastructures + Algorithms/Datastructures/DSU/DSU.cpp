vector<int> parent;
vector<int> sizes;
int sets = 0;

void make_set(int& v) {
	parent[v] = v;
	sizes[v] = 1;
	sets++;
}

int find_set(int v) {
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (sizes[a] < sizes[b]) {
			swap(a, b);
		}
		parent[b] = a;
		sizes[a] += sizes[b];
		sets--;
	}
}