#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <cstring>
using namespace std;

long long dist(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first) swap(a, b);
	if (a.second >= b.first) return 0;
	return (b.first - a.second);

}

void solve(vector<long long> & res, vector<vector<long long> > & v, vector<pair<int, int> > & segs) {
	vector<int> seg;
	int col = -1;
	map<int, int> m;
	int cols = 0;
	for (int i = 0; i < v.size(); i++) {
		vector<long long> cur = v[i];
		if (cur[1] == 0) {
			m[cur[3]]++;
			if (m[cur[3]] == 1) cols++;
			if (col != cur[3]) {
				for (int j = 0; j < seg.size(); j++) {
					res[seg[j]] = min(res[seg[j]], dist(segs[seg[j]], segs[cur[2]]));
					res[cur[2]] = min(res[cur[2]], dist(segs[seg[j]], segs[cur[2]]));
				}
				seg.clear();
				col = cur[3];
			}
			seg.push_back(cur[2]);
			if (cols > 1) {
				for (int j = 0; j < seg.size(); j++) {
					res[seg[j]] = 0;
				}
				seg.clear();
			}

		} else {
			m[cur[3]]--;
			if (m[cur[3]] == 0) cols--;
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<vector<long long> > v;
		vector<vector<long long> > v2;
		vector<pair<int, int> > segs(n);
		for (int i = 0; i < n; i++) {
			int l, r, c;
			cin >> l >> r >> c;
			v.push_back({l, 0, i, c});
			v.push_back({r, 1, i, c});
			v2.push_back({r, 0, i, c});
			v2.push_back({l, 1, i, c});
			segs[i] = {l, r};
		}
		sort(v.begin(), v.end());
		sort(v2.begin(), v2.end());
		vector<long long> res(n, 1e18);
		solve(res, v, segs);
		reverse(v2.begin(), v2.end());
		solve(res, v2, segs);
		//reverse(res.begin(), res.end());
		for (int i = 0; i < n; i++) {
			cout << res[i];
			if (i == n - 1) cout << endl;
			else cout << " ";
		}
	}
	return 0;
}
