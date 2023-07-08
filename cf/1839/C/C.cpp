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
		if (a[n - 1] == 1) {
			cout << "NO" << endl;
			continue;
		}
		vector<int> res;
		int last = 0;
		int cnt = 0;

		for (int i = n - 1; i >= 0; i--) {	
			if (a[i] == 0 && a[i] != last) {
				res[res.size() - 1] = cnt;
			} 
			if (a[i] == 1) cnt++;
			else cnt = 0;
			res.push_back(0);
			last = a[i];
			
		}	
		if (a[0] == 1) {
			res[res.size() - 1] = cnt;
		}
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << res[i] << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
