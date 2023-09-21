#include <bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> a(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		map<int, vector<int> > m;
		int maxi = 0;
		int mc = 0;
		for (int i = 0; i < n; i++) {
			m[a[i]].push_back(a[i]);
			maxi = max(maxi, a[i]);
		}
		if (m[maxi].size() == n) {
			cout << -1 << endl;
			continue;
		}
		cout << n - m[maxi].size() << " " << m[maxi].size() << endl;
		vector<int> b;
		vector<int> c;
		for (auto it : m) {
			for (auto x : it.second ){
				if (it.first == maxi) {
					c.push_back(x);
				} else {
					b.push_back(x);
				}
			}
		}
		for (int i =0 ; i < b.size(); i++) {
			cout << b[i] << " \n"[i == b.size() - 1];
		}
		for (int i = 0; i < c.size(); i++) {
			cout << c[i] << " \n"[i == c.size() - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
