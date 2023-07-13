#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<string> c(n);
	map<string, int> d;
	for (int i = 0; i < n ;i++) {
		cin >> c[i];
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		d[s] = i + 1;
	}
	vector<int> p(m + 1);
	for (int i = 0; i < m + 1; i++) {
		cin >> p[i];
	}
	int res = 0;
	for (string & s : c) {
		res += p[d[s]];
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
