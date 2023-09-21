#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<long long> p(n);
	multiset<long long> s;

	long long res = 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		s.insert(p[i]);
		res += p[i];
	}
	vector<pair<long long, long long> > v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i].second;
	}
	for (int i = 0; i < m; i++) {
		cin >> v[i].first;
	}

	sort(v.begin(), v.end());
	for (int i = m - 1; i >= 0; i--) {
		auto it = s.lower_bound(v[i].second);
		if (it != s.end()) {
			s.erase(it);
			res -= v[i].first;
		}
	}
	cout << res << endl;



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
