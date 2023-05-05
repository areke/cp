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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m;
		cin >> n >> m;
		string res = "";
		vector<pair<long long, long long> > v(n);
		vector<vector<long long> > vi(n);
		for (int i = 0; i < n; i++) {
			long long x, p;
			cin >> x >> p;
			vi[i] = {x, p, i};
			v[i] = {x, p};
		}

		
		sort(v.begin(), v.end());

		sort(vi.begin(), vi.end());

		vector<long long> l(v.size());
		vector<long long> r(v.size());
		long long s = 0;
		for (int i = 0; i < v.size(); i++) {
			while (!pq.empty() && (-pq.top() - v[i].first <= 0)) {
				s -= pq.top();
				pq.pop();
			}
			l[i] = s - (pq.size() * v[i].first);
			pq.push(-v[i].first - v[i].second);
			s += v[i].first + v[i].second;
		}
		while (!pq.empty()) pq.pop();
		s = 0;
		for (int i = v.size() - 1; i >= 0; i--) {
			while (!pq.empty() && v[i].first  + (-pq.top()) <= 0) {
				s -= pq.top();
				pq.pop();
			}
			r[i] = s + pq.size() * v[i].first;
			s += v[i].second - v[i].first;
			pq.push(-(v[i].second - v[i].first));
		}
		string res(n, '0');
		for (int i = 0; i < n; i++) {
			
			res[vi[i][2]] = 
		}


		
		for (int i = 0; i < n; i++) {
			node cur = seg.query(mp[i], mp[i]);
			seg.upd(mp[i], node({}, 0));
			long long v = seg.query(0, n - 1).maxi;
			seg.upd(mp[i], cur);
			if (v > m) {
				res += '0';
			} else {
				res += '1';
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
