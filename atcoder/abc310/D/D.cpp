#include <bits/stdc++.h>
using namespace std;

int res = 0;
int n, t;

set<vector<vector<int > > > cnt;

void solve(vector<vector<int> > & all, int ind, set<pair<int, int> > & bad) {
	if (ind == n) {
		set<int> f;
		if (all.size() == t) {
			bool can = true;
			auto next = all;
			for (auto & x : next) {
				if (x.empty()) can = false;
				for (int j : x) {
					f.insert(j);
				}
				sort(x.begin(), x.end());
			}
			sort(next.begin(), next.end());
			if (can && f.size() == n) cnt.insert(next);
		}
		return;
	}
	for (int i = 0; i < all.size(); i++) {
		all[i].push_back(ind);
		bool can = true;
		for (int j : all[i]) {
			if (bad.count({ind, j})) can = false;
			
		}
		if (can) solve(all, ind + 1, bad);
		all[i].pop_back();
	}
	all.push_back({ind});
	solve(all, ind + 1, bad);
	all.pop_back();
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> t >> m;
	
	set<pair<int, int> > bad;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		bad.insert({x, y});
		bad.insert({y, x});
	}
	vector<vector<int> > all = {{}};
	solve(all, 0, bad);
	cout << cnt.size() << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
