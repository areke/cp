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
		vector<long long> v(n);
		set<long long> s;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < n; i++) {
			s.insert(v[i]);
		}
		if (s.size() >= 7) {
			cout << "NO" << endl;
			continue;
		}
		map<long long, int> m;
		for (int i = 0; i < v.size(); i++) {
			m[v[i]]++;
		}

		vector<long long> a;
		for (auto it : m) {
			for (int j = 0; j < min(3, it.second); j++) {
				a.push_back(it.first);
			}
		}
		bool can = true;
		for (int i = 0; i < a.size(); i++) {
			for (int j = i + 1; j < a.size(); j++) {
				for (int k = j + 1; k < a.size(); k++) {
					long long su = a[i] + a[j] + a[k];
					if (s.find(su) == s.end()) can = false;
				}
			}
		}
		if (can) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
