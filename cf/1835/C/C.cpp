#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int k;
		cin >> k;
		int n = 1 << (k + 1);
		long long mask = (1LL << k) - 1;
		vector<long long> v(n, 0); 
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<long long> p(n + 1, 0);
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] ^ v[i];
		}
		map<long long, int> m;
		map<long long, pair<int, int> > s;
		vector<pair<int, int> > res;
		for (int i = 0; i <= n; i++) {
			if (m.count(p[i] & mask)) {
				pair<int, int> cur = {m[p[i] & mask] + 1, i};
				int l = m[p[i] & mask];
				if (s.count(p[i] ^ p[l])) {
					auto old = s[p[i] ^ p[l]];
					res = {old, cur};
					break;
				}
				s[p[i] ^ p[l]] = cur;
			}
			m[p[i] & mask] = i;
		}
		if (res[0].first > res[1].first) {
			swap(res[0], res[1]);
		}
		assert(res[0] < res[1]);
		if (res[0].second >= res[1].second) {
			res = {{res[0].first, res[1].first - 1}, {res[1].second + 1, res[0].second}};
		} else if (res[0].second >= res[1].first) {
			swap(res[0].second, res[1].first);
			res[0].second--;
			res[1].first++;
		}

		for (int i = 0; i < 2; i++) {
			//if (res[i].first + 1 > res[i].second) swap(res[i].first, res[i].second);
			cout << res[i].first << " " << res[i].second << " \n"[i == 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
