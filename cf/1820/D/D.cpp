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

bool can(long long h, long long w, int axis, map<long long, multiset<long long> > & hm, map<long long, multiset<long long> > & wm) {
	//cout << h << " " << w << " " << axis << " " << hm.size() << endl;
	if (h == 0 || w == 0) {
		return hm.empty();
	}
	if (hm.empty()) return false;
	if (axis == 0) {
		long long sm = 0;
		for (long long wid : hm[h]) {
			sm += wid;
			if (!wm.count(wid) || (wm[wid].find(h) == wm[wid].end() )) {
				return false;
			}
			wm[wid].erase(wm[wid].find(h));
			if (wm[wid].empty()) {
				wm.erase(wm.find(wid));
			}
		}
		if (sm == 0) return false;
		hm.erase(hm.find(h));
		return can(h, w - sm, axis ^ 1, hm, wm);
	} else {
		long long sm = 0;
		for (long long hei : wm[w]) {
			sm += hei;
			if (!hm.count(hei) || (hm[hei].find(w) == hm[hei].end())) {
				return false;
			}
			hm[hei].erase(hm[hei].find(w));
			if (hm[hei].empty()) {
				hm.erase(hm.find(hei));
			}
		}
		if (sm == 0) return false;
		wm.erase(wm.find(w));
		return can(h - sm, w, axis ^ 1, hm, wm);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		map<long long, multiset<long long> > h;
		map<long long, multiset<long long> > w;
		
		long long area = 0;
		for (int i = 0; i < n; i++) {
			long long x, y;
			cin >> x >> y;
			h[x].insert(y);
			w[y].insert(x);
			area += x * y;
		}
		map<long long, multiset<long long> > h2 = h;
		map<long long, multiset<long long> > w2 = w;
		long long maxh = (*(h.rbegin())).first;
		long long maxw = (*(w.rbegin())).first;
		set<pair<long long, long long> > res;
		if (area % maxh == 0 && can(maxh, area / maxh, 0, h, w)) {
			res.insert({maxh, area / maxh});
		}
		if (area % maxw == 0 && can(area / maxw, maxw, 1, h2, w2)) {
			res.insert({area / maxw, maxw});
		}
		cout << res.size() << endl;
		for (auto it : res) {
			cout << it.first << " " << it.second << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
