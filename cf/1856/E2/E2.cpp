#include <bits/stdc++.h>
using namespace std;
 
int dfs(int x, vector<vector<int> > & v, vector<int> & c, int last = -1) {
	int res = 1;
	for (int n : v[x]) {
		if (n == last) continue;
		res += dfs(n, v, c, x);
	}
	return c[x] = res;
}
 
long long solve(int x, vector<vector<int> > & v, vector<int> & c, int last = -1) {
	long long res = 0;
	map<long long, int> m;
	long long su = c[x] - 1;
	long long mx = 0;
	for (int n : v[x]) {
		if (n == last) {
			continue;
		}
		res += solve(n, v, c, x);
		m[c[n]]++;
		mx = max(mx, 1LL * c[n]);
	}
	if (mx > c[x] / 2) {
		return res + mx * (su - mx);
	}
	vector<long long> as;
	for (auto it : m) {
		for (int j = 0; j < 20; j++) {
			long long cur = 0;
			long long next = 1 << j;
			if (cur + next <= it.second) {
				cur += it.second;
				as.push_back(next * it.first);
			} else {
				if (it.second - cur - next > 0) {
					as.push_back((it.second - cur) * it.first);
				}
			}
		}
	}
	set<long long> s = {0};
	for (int i = 0; i < as.size(); i++) {
		//cout << as[i] << endl;
		vector<long long> ns;
		for (int y : s) {
			if (y + as[i] > su / 2) continue;
			ns.push_back(y + as[i]);
		}
		for (int y : ns) {
			s.insert(y);
		}	
	}
 
	long long maxi = 0;
	for (auto y : s) {
		maxi = max(maxi, (su - y) * y);
	}
	return res + maxi;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int> > v(n);
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		x--;
		v[i].push_back(x);
		v[x].push_back(i);
	}
	vector<int> c(n, 0);
	dfs(0, v, c);
	long long res = 0;
	cout << solve(0, v, c) << endl;
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
 
	return 0;
}