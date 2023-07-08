#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] = n - a[i];
		}
		long long m;
		cin >> m;
		map<long long, long long> c;
		c[n] = n;
		map<int, vector<int> > inds;
		set<pair<int, int> > all;
		all.insert({n - 1, 0});
		for (int i = 0; i < n; i++) {
			inds[a[i]].push_back(i);
		}
		long long res = 0;
		int tot = n;
		for (int i = 0; i <= n; i++) {
			for (int j : inds[i]) {
				auto it = all.lower_bound({j, -1});
				pair<int, int> p = *it;
				c[p.first - p.second + 1] -= n - i;
				all.erase(it);
				tot--;
				if (p.second <= j - 1) {
					all.insert({j - 1, p.second});
					c[j - 1 - p.second + 1] += n - i;
				}
				if (j + 1 <= p.first) {
					all.insert({p.first, j + 1});
					c[p.first - j - 1 + 1] += n - i;
				}
			}

		}
		for (auto it = c.rbegin(); it != c.rend(); it++) {
			if (it->first <= 1) break;
			if (m >= (it->first) * (it->second)) {
				res += (it->first - 1) * it->second;
				m -= (it->first) * (it->second);
			} else {
				long long t = m / (it->first);
				res += (it->first - 1) * t;
				m -= t * it->first;
				//cout << "K " << m << endl;
				res += max(0LL, m - 1);
				break;
			}
		}
		cout << res << endl;




	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
