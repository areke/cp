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

		vector<long long> x(n);
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			x[i] = v[i];
		}
		sort(v.begin(), v.end());
		vector<long long> p(n + 1);
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] + v[i];
		}
		for (int i = 0; i < n; i++) {
			auto ind = upper_bound(v.begin(), v.end(), x[i]) - v.begin();
			ind--;
			
			long long res = (x[i] + 1) * (ind + 1) - p[ind + 1];
			//cout << i << " " << ind << " " << res << " " << p[n] << " " << p[ind + 1] << endl;
			res += (p[n] - p[ind + 1]) - (x[i] - 1) * (n - ind - 1);
			cout << res << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
