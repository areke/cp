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
		vector<int> b(n);
		int cnt = 0;
		int last = a[0];
		map<int, int> ma;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		map<int, int> mb;
		for (int i = 0; i < n; i++) {
			if (a[i] == last) cnt++;
			else {
				
				cnt = 1;
				last = a[i];
			}
			ma[a[i]] = max(ma[a[i]], cnt);
		}
		ma[a[n - 1]] = max(ma[a[n - 1]], cnt);
		last = b[0];
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (b[i] == last) cnt++;
			else {
				cnt = 1;
				last = b[i];
			}
			mb[b[i]] = max(mb[b[i]], cnt);


		}
		mb[b[n - 1]] = max(mb[b[n - 1]], cnt);
		int res = 0;
		for (int i = 0; i < n; i++) {
			res = max(res, ma[a[i]] + mb[a[i]]);
		}

		for (int i = 0; i < n; i++) {
			res = max(res, ma[b[i]] + mb[b[i]]);
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
