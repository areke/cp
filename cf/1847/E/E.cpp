#include <bits/stdc++.h>
using namespace std;

	// find non-degenerate triangle using first 4 points:

	// if non-degenerate isosceles triangle exists, find third side.
		// query second triangle with two common points and take max area. then
		// we know the largest 2 sides so we can uniquely determine every other point.
		// then determine which is which at the end.
	// if equilateral and side > 1 same.
	// if equilateral and side == 1, then query points until find two degenerate triangles, and use those to determine the rest.

	// brute force points until finding a non-degenerate triangle:
		// query second triangle, then take max area triangle out of 4 points. at least 1 must be non-degenerate.

	// win if find 2 2s.
	// win if find 2 and 3, win if find 33 or 44

	// 1 1, 1 2, 1 3, 1 4 
	// 2 2, 2 3, # win 2 4
	// 3 3, 3 4 # win
	// 4 4 # win


	// if degen at least one is 3 or 4, or it is 112

int query(int i, int j, int k) {
	cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
	int x;
	cin >> x;
	return x;
}

int main() {
	map<long long, vector<vector<int> > > m;
	map<multiset<int>, int> invm;
	
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				bool deg = false;
				if (i + j <= k || i + k <= j || j + k <= i) deg = true;
				if (deg) {
					m[0].push_back({i, j, k});
					continue;
				}
				int s =  (i + j + k);
				long long a = 1LL * s * (s - 2 * i) * (s - 2 * j) * (s - 2 * k);
				m[a].push_back({i, j, k});
				invm[{i, j, k}] = a;
			}
		}
	}
	/*
	for (auto it : m) {
		cout << it.first << " ";
		
		for (int i = 0; i < it.second.size(); i++) {
			cout <<"(";
			for (int j =0 ; j< 3; j++) {
				cout << it.second[i][j] <<",";
			}
			cout << ")";
		}
		cout << endl;
	}*/
	int n;
	cin >> n;

	vector<int> res(n, 0);
	
	if (n == 3) {
		cout << "! -1" << endl;
		return 0;
	}

	// find positions of two sides > 1 that are equal 
	// find isosceles triangle out of first 5 points
	// there is either an equilateral triangle of 1s, or an isosceles triangle of lengths > 1
	vector<int> eq;
	vector<int> is;
	int isval = 0;
	set<int> vals;
	for (int i = 0; i < 64; i++) {
		vector<int> v;
		for (int j = 0; j < min(n, 6); j++) {
			if ((i >> j) & 1) {
				v.push_back(j);
			}
		}
		if (v.size() != 3) continue;
		int val = query(v[0], v[1], v[2]);
		vals.insert(val);
		if (val == 3) {
			eq = v;
		} else if (val != 0 && val != 135) {
			if (m[val].size() < m[isval].size()) {
				is = v;
				isval = val;
			}
		}
	}

	if (is.empty()) {
		assert(!eq.empty());
		for (int x : eq) res[x] = 1;
		vector<int> cands;
		for (int i = 0; i < n; i++) {
			if (res[i]) continue;
			int val = query(eq[0], eq[1], i);
			if (val == 3) {
				res[i] = 1;
				continue;
			}
			cands.push_back(i);
			if (cands.size() == 5) break;
		}
		if (cands.empty()) {
			cout << "! ";
			for (int i = 0; i < n; i++) {
				cout << 1 << " \n"[i == n - 1];
			}
			cout << endl;
			return 0;
		}
		cands.push_back(eq[0]);
		cands.push_back(eq[1]);
		for (int i = 0; i < (1 << cands.size()); i++) {
			vector<int> v;
			for (int j = 0; j < cands.size(); j++) {
				if ((i >> j) & 1) {
					v.push_back(cands[j]);
				}
			}
			if (v.size() == 3) {
				int val = query(v[0], v[1], v[2]);
				if (val != 135) {
					// prefer equilateral then isosc then area = 63
					if (m[val].size() < m[isval].size()) {
						is = v;
						isval = val;
					}
				}
			}
		}
	}
	
	if (is.empty()) {
		cout << "! -1" << endl;
		return 0;
	}
	vector<int> sides;
	
	if (isval == 63) {
		if (n >= 5) {
			
			// could be 4, 4, 1, 1, 1
			// but 2, 2, 3, 4 is the maximal set without having an another isosceles tri
			sides = {4, 4, 1};
		} else if (n == 4) {
			// 2, 2, 3, 4 vs 4, 4, 1, 1
			if (vals.count(135)) {
				sides = {2, 2, 3};
			} else {
				sides = {4, 4, 1};
			}
		}
	} else {
		sides = m[isval][0];
	}
	vector<int> cur;

	int side;
	if (sides[0] == sides[1] && sides[1] == sides[2]) {
		cur = {is[0], is[1]};
		res[is[0]] = sides[0];
		res[is[1]] = sides[1];
	} else {
		int ind = -1;
		for (int i = 0; i < 4; i++) {
			bool can = true;
			for (int j = 0; j < 3; j++) {
				if (i == is[j]) can = false;
			}
			if (can) {
				ind = i;
				break;
			}
		}
		if (sides[0] == sides[1] || sides[0] == sides[2]) side = sides[0];
		else side = sides[1];
		bool found = false;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j || found) continue;
				int val = query(is[i], is[j], ind);
				if (val == 0) continue;
				
				for (int k = 0; k < m[val].size(); k++) {
					int cnt = 0;
					for (int l = 0; l < 3; l++) {
						if (m[val][k][l] == side) cnt++;
					}
					if (cnt == 2) {
						found = true;
						break;
					}
				}
				if (found) {
					cur = {is[i], is[j]};
					res[is[i]] = side;
					res[is[j]] = side;
				}
			}
		}

		if (!found) {
			if (find(sides.begin(), sides.end(), 3) != sides.end()) {
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (i == j || found) continue;
						int val = query(is[i], is[j], ind);
						if (val == 0) {
							found = true;
						}
						if (found) {
							cur = {is[i], is[j]};
							res[is[i]] = side;
							res[is[j]] = side;
						}
					}
				}
			} else  {
				// must be 221 and res[ind] = 4
				if (n == 4) {
					cout << "! -1" << endl;
					return 0;
				}
				int ind2 = ind;
				for (int i = 0; i < 5; i++) {
					bool can = true;
					for (int j = 0; j < 3; j++) {
						if (i == is[j]) can = false;
					}
					if (i == ind2) can = false;
					if (can) {
						ind = i;
						break;
					}
				}
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (i == j || found) continue;
						int val = query(is[i], is[j], ind);
						if (val == 0) continue;
						
						for (int k = 0; k < m[val].size(); k++) {
							int cnt = 0;
							for (int l = 0; l < 3; l++) {
								if (m[val][k][l] == side) cnt++;
							}
							if (cnt == 2) {
								found = true;
								break;
							}
						}
						if (found) {
							cur = {is[i], is[j]};
							res[is[i]] = side;
							res[is[j]] = side;
						}
					}
				}
				if (!found) {
					cur = {ind, ind2};
					res[ind] = 4;
					res[ind2] = 4;
					side = 4;
				}
			}
		}

	}
	assert(!cur.empty());
	for (int i = 0; i < n; i++) {
		if (res[i]) continue;
		int val = query(cur[0], cur[1], i);
		vector<int> v = {cur[0], cur[1], i};
		int ac = -1;
		for (vector<int> & x : m[val]) {
			int cnt = 0;
			for (int j = 0; j < 3; j++) {
				if (x[j] == side) cnt++;
			}
			if (cnt >= 2) {
				ac = x[0] ^ x[1] ^ x[2];
				break;
			}
		}
		assert(ac != -1);
		res[i] = ac;
	}
	cout << "! ";
	for (int i = 0; i < n; i++) {
		cout << res[i] << " \n"[i == n - 1];
	}
	cout.flush();
	
	







	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
