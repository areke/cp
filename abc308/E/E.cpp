#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	string s;
	cin >> s;
	long long res = 0;
	vector<vector<int> > v(3, vector<int>(3, 0));
	map<set<int>, long long> m;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'E') {
			for (int j = 0; j < 3; j++) {
				m[{j, a[i]}] += v[2][j];
			}
			v[1][a[i]]++;
		} else if (s[i] == 'X') {
			v[2][a[i]]++;
		} else { 
			v[0][a[i]]++;
			for (auto & s : m) {
				auto ss = s.first;
				ss.insert(a[i]);
				int mex = 0;
				for (int j = 0; j < 3; j++) {
					if (ss.count(j)) mex++;
					else break;
				}
				res += s.second * mex;
			}
		}
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
