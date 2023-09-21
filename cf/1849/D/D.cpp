#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int dir, vector<int> & a, vector<bool> & vis) {
	if (x < 0 || x >= a.size()) return;
	if (vis[x]) return;
	vis[x] = true;
	if (a[x] == 0) return;
	if (a[x] == 1) {
		dfs(x + dir, dir, a, vis);
	} else {
		for (int i = -1; i < 2; i+= 2) {
			dfs(x + i, i, a, vis);
		}
	}
}

int score(vector<int> & v) {
	if (v.empty()) return 0;
	int tot = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!v[i]) tot++;
	}
	bool add = true;
	if (v.back() != 1 || v[0] != 1) add = false;
	int cur = 1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == 0 && v[i - 1] == 0) add = false;
	}
	if (add) tot++;
	return tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<bool> vis(n, 0);
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 2 && !vis[i]) {
			dfs(i, 0, a, vis);
			res++;
		}
	}
	vector<int> comp;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			comp.push_back(a[i]);
		} else {
			res += score(comp);
			comp.clear();
		}
	}
	res += score(comp);
	cout << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
