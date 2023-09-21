#include <bits/stdc++.h>
using namespace std;
 
 
int n;
int qc = 0;
 
int query(int u, int k, vector<int> v) {
	qc++;
	cout << "? " << u << " " << k << " " << v.size() << " ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	} 
	cout << endl;
	cout.flush();
	int x;
	cin >> x;
	return x;
}
 
int resolve(int start, int k) {
	set<int> cur;
	for (int i = 1; i <= n; i++) {
		cur.insert(i);
	}
	while (cur.size() > 1) {
		int cnt = 0;
		vector<int> v;
		for (auto it : cur) {
			if (cnt >= cur.size() / 2) break;
			v.push_back(it);
			cnt++;
		}
		if (query(start, k, v)) {
			cur = set(v.begin(), v.end());
		} else {
			for (int x : v) {
				cur.erase(x);
			}
		}
 
	}
	return *cur.begin();
}
 
int getLen(int x, set<int> & cyc, int maxi = 1e9) {
	vector<int> v(cyc.begin(), cyc.end());
	int cnt = cyc.size();
	int sz = cyc.size();
	bool f = false;
	while (sz <= maxi) {
		int can = query(x, sz, v);
		if (can) {
			f = true;
			break;
		}
		sz += cyc.size();
	}
	if (!f) {
		return -1;
	}
	vector<int> y = {x};
	for (int i = 0; i <= cyc.size(); i++) {
		if (sz + i == 0) continue;
		int can = query(x, sz + i, y);
		if (can) {
			return sz + i;
		}
	}
	return -1;
}
 
int main() {
 
	cin >> n;
	// get start of cycle (10 queries)
	// find 10 things in cycle (100 queries)
	// find cycle length (~50 queries)
 
	// if cycle length <= 140 just figure out everything
	// if > 250 there can only be 1 cycle
	// so find things that have the same cycle length (500 queries)
 
 
	// otherwise find 84 in the cycle (840 queries)... 900 total so far
	// now query the rest of the 416 3x in a random order, with random jumps.
	// 
	vector<int> res;
 
	
	int start = resolve(1, 1000);
	set<int> cyc = {start};
	bool found = false;
	int curc = 65;
	//sdfLKJFLKASJFSA
	while (cyc.size() < curc) {
		start = resolve(start, 1);
		if (cyc.count(start)) {
			found = true;
			break;
		}
		cyc.insert(start);
	}
	if (!found) {
		assert(cyc.size() == curc);
		for (int j = 0; j < 3; j++) {
			vector<int> cycle(cyc.begin(), cyc.end());
			int cz = cyc.size();
			for (int i = 1; i <= n; i++) {
				if (cyc.count(i)) continue;
				if (query(i, curc, cycle)) {
					cyc.insert(i);
				}
			}
			curc *= 2;
 
			if (cyc.size() < curc) break;
			// 65, 130, 260, 
		}	
	}
	vector<int> cycle(cyc.begin(), cyc.end());
	for (int i = 1; i <= n; i++) {
		if (cyc.count(i)) {
			res.push_back(i);
		} else {
			if (query(i, 1000, cycle)) {
				res.push_back(i);
			}
		}
	}
	cout << "! " << res.size() << " ";
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
 
	
 
	
 
	// need 500ish at the end
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
 
	return 0;
}