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
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;
 
 
// o(a*b)
vector<long long> merge(vector<long long> & a, vector<long long> & b) {
	
	vector<long long> v(a.begin(), a.end());
	for (long long x : b) {
		long long cur = x;
		int p = 30;
		for (int i = 0; i < v.size(); i++) {
			bool b = false;
			while (!b && p >=0	) {
				if (((1 << p) & cur) && (1 << p) & v[i]) {
					cur ^= v[i];
					p--;
					b = true;
				} else if (((1 << p) & cur) && !((1 << p) & v[i])) {
					v.insert(v.begin() + i, cur);
					cur = 0;
					goto stop;
				} else if ((1 << p) & v[i]) {
					p--;
					b = true;
				} else {
					p--;
				}
			}
		}
		stop:
		if (cur) {
			v.push_back(cur);
		}
	}
	return v;
}
 
 
vector<long long> dfs(int x, vector<vector<int> > & v, vector<vector<long long> > & b, vector<long long> & a, int l) {
	if (b[x].size()) return b[x];
	vector<long long> cb = {a[x]};
	for (int n : v[x]) {
		if (n == l) continue;
		vector<long long> nb = dfs(n, v, b, a, x);
		cb = merge(cb, nb);
	}
	return b[x] = cb;
}
 
void dfs2(int x, int & cur, vector<vector<int> > & v, vector<long long> & d, vector<long long> & f, int l) {
	if (d[x] >= 0) return;
	cur++;
	d[x] = cur;
	for (int n : v[x]) {
		if (n == l) continue;
		dfs2(n, cur, v, d, f, x);
	}
	f[x] = cur;
	cur++;
}
 
long long solve(vector<long long> & v) {
	long long res = 0;
	for (long long c : v) {
		if ((res ^ c) > res) {
			res ^= c;
		}
	}
	return res;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<vector<int> > v(n);
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		vector<vector<long long> > b(n);
		vector<long long> f(n, -1);
		vector<long long> d(n, -1);
		dfs(0, v, b, a, -1);
		int cur = 0;
		dfs2(0, cur, v, d, f, -1);
		int q;
		cin >> q;
		vector<pair<long long, int> > fv(n);
		vector<pair<long long, int> > dv(n);
		
		for (int i = 0; i < n; i++) {
			fv[i] = {f[i], i};
			dv[i] = {d[i], i};
		}
		sort(fv.begin(), fv.end());
		sort(dv.begin(), dv.end());
		vector<vector<long long> > bd(2 * n + 10);
		vector<vector<long long> > bd2(2 * n + 10);
		//cout << "HUH "<< endl;
		for (int i = 0; i < n; i++) {
			bd[d[i]] = { a[i] };
			bd2[d[i]] = { a[i] };
		}
		for (int i = 1; i <= 2 * n; i++) {
			bd[i] = merge(bd[i - 1], bd[i]);
		}
		for (int i = 2 * n - 1; i >= 0; i--) {
			bd2[i] = merge(bd2[i + 1], bd2[i]);
		}
		//cout << "HUH "<< endl;
		vector<vector<pair<long long, int> > > vd(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				vd[i].push_back({d[v[i][j]], v[i][j]});
			}
			sort(vd[i].begin(), vd[i].end());
		}
		for (int i = 0; i < q; i++) {
			int r, x;
			cin >> r >> x;
			r--;
			x--;
			//cout << r << " " << x << " " << i << endl;
			long long res = -1;
			if (d[x] < d[r] && f[x] > f[r]) {
				int low = 0;
				int high = (int)vd[x].size() - 1;
				int best = -1;
				
				while (low <= high) {
					int mid = (low + high) / 2;
					//cout << " " << vd[x][mid].first << " " << vd[x][mid].second << " " << d[x] << " " << f[x] << endl;
					
					if (vd[x][mid].first > d[r]) {
						high = mid - 1;
					} else if (f[vd[x][mid].second] < f[r]) {
						low = mid + 1;
					} else {
						
						best = mid;
						low = mid + 1;
					}
				}
 
				assert(best >= 0);
				int ind = vd[x][best].second;
				vector<long long> cb = merge(bd2[f[ind] + 1], bd[d[ind] - 1]);
				res = solve(cb);
			} else if (x == r) {
				res = solve(b[0]);
			} else{
				res = solve(b[x]);
			}
			cout << res << endl;
		}
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
