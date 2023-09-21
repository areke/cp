#include <bits/stdc++.h>
using namespace std;

long long lpow(long long x, long long p) {
	if (p == 0) return 1;
	long long res = lpow(x, p / 2);
	res *= res;
	if (p & 1) res *= x;
	return res;
}

long double logb(long long x, long long y) {
	long double a = x;
	long double b = y;
	return log2(a) / log2(b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tests;
	cin >> tests;
	map<long long, vector<int> > m;
	vector<string> res(tests, "NO");
	for (int test = 1; test <= tests; test++) {
		long long n;
		cin >> n;
		m[n].push_back(test - 1);
		// k ^2 + k - (n - 1) = 0
		// -1 +/- sqrt(1 + 4n + 4) / 2

		long long k = (-1 + sqrt(1 + 4*n + 4)) / 2;
		
		if ((k * k + k + 1) == n && k > 1) {
			res[test - 1] = "YES";
		}
	}
	long long maxi = 1e6;
	long long M = 1e18;
	
	for (long long k = 2; k <= 1e7; k++) {
		long long su = 1 + k;
		long long b = k;
		for (long long i = 3; i <= 62; i++) {
			//cout << logb(m, i) + logb(k - 1, i) << " " << k << endl;
			if (logb(M, k) + 1 < (long double)i) {
				break;
			}
			b *= k;
			su += b;
			auto it = m.find(su);
			if (it != m.end()) {
				for (int x : it->second) {
					res[x] = "YES";
				}
			}
			//cout << su << endl;
		}
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
