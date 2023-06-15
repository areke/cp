#include <bits/stdc++.h>
using namespace std;

int bit[1001][1001];
int n;

void update(int x, int y, int val) {
	for (; x <= n; x += (x & (-x))) {
		for (int i = y; i <= n; i += (i & (-i))) { bit[x][i] += val; }
	}
}

int query(int x1, int y1, int x2, int y2) {
	int ans = 0;
	for (int i = x2; i; i -= (i & (-i))) {
		for (int j = y2; j; j -= (j & (-j))) { ans += bit[i][j]; }
	}
	for (int i = x2; i; i -= (i & (-i))) {
		for (int j = y1 - 1; j; j -= (j & (-j))) { ans -= bit[i][j]; }
	}
	for (int i = x1 - 1; i; i -= (i & (-i))) {
		for (int j = y2; j; j -= (j & (-j))) { ans -= bit[i][j]; }
	}
	for (int i = x1 - 1; i; i -= (i & (-i))) {
		for (int j = y1 - 1; j; j -= (j & (-j))) { ans += bit[i][j]; }
	}
	return ans;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	vector<vector<int> > v(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '*') v[j][i] = 1;
			else v[j][i] = 0;
			update(j + 1, i + 1, v[j][i]);
		}
	}
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> y >> x;
			x--;
			y--;
			v[x][y] ^= 1;
			if (v[x][y]) update(x + 1, y + 1, 1);
			else update(x + 1, y + 1, -1);
		} else if (t == 2) {
			int a, b, c, d;
			cin >> b >> a >> d >> c;
			a--;
			b--;
			c--;
			d--;
			ans.push_back(query(a + 1, b + 1, c + 1, d + 1));
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}