#include <bits/stdc++.h>
using namespace std;

void dfs(int x, vector<vector<int> > & v, vector<int> & a, int last) {
	a[x] = last == -1 ? 0 : a[last] + 1;
	for (int n : v[x]) {
		if (n == last) continue;
		dfs(n, v, a, x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int> > v(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<int> a(n, 0);
	dfs(0, v, a, -1);
	int best = max_element(a.begin(), a.end()) - a.begin();
	vector<int> b(n, 0);
	dfs(best, v, b, -1);
	cout << *max_element(b.begin(), b.end()) << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
