#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	long long n;
	cin >> n;
	vector<vector<int> > primes(1e6 + 1);
	for (int i = 2; i <= 1e6; i++) {
		if (primes[i].size()) continue;
		for (int j = i; j <= 1e6; j += i) {
			primes[j].push_back(i);
		}
	}
	vector<long long> m(1e6 + 1, 0);
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		m[v[i]]++;
	}
	vector<long long> c(1e6 + 1, 0);
	for (int i = 2; i <= 1e6; i++) {
		for (int j = i; j <= 1e6; j+=i) {
			c[i] += m[j];
		} 
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		long long cnt = 0;
		for (int j = 1; j < (1 << primes[v[i]].size()); j++) {
			int cur = 1;
			int num = 0;
			for (int k = 0; k < primes[v[i]].size(); k++) {
				if ((1 << k) & j) {
					cur *= primes[v[i]][k];
					num++;
				}
			}
			if (num % 2) {
				cnt += c[cur];
			} else {
				cnt -= c[cur];
			}
			
		}
		res += cnt;
		if (cnt) res--;
	}
	cout << n * (n - 1) / 2 - res / 2 << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
