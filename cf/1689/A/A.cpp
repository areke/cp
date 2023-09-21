#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m, k;
		cin >> n >> m >> k;
		string a, b;
		cin >> a >> b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int x = 0, y = 0;
		int cur[2] = {0};
		string res = "";
		while (x < n && y < m) {
			int p = 0;
			if (cur[0] == k) {
				p = 1;
				res += b[y];
				y++;
				
			} else if (cur[1] == k) {
				p = 0;
				res += a[x];
				x++;
				
			} else if (a[x] < b[y]) {
				p = 0;
				res += a[x];
				x++;
				
			} else {
				p = 1;
				res += b[y];
				y++;
				
			}
			cur[p]++;
			cur[p ^ 1] = 0; 
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
