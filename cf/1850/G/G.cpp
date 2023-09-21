#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		map<long long, long long> x;
		map<long long, long long> y;
		map<long long, long long> xy;
		map<long long, long long> yx;
		int n;
		cin >> n;
		vector<pair<long long, long long> > v(n);
		for (int i = 0; i < n; i++){
			long long a, b;
			cin >> a >> b;
			v[i] = {a, b};
			x[a]++;
			y[b]++;
			xy[a + b]++;
			yx[b - a]++;
		}
		long long res = 0;
		for (int i = 0; i < n; i++) {
			long long a = v[i].first;
			long long b = v[i].second;
			res += x[a] - 1;
			res += y[b] - 1;
			res += xy[a + b] - 1;
			res += yx[b - a] - 1; 
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
