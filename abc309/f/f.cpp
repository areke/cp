#include <bits/stdc++.h>
using namespace std;

int MAX = 2e9;

template<class T> struct Seg {
	const T ID = MAX;
	T comb(T a, T b) {
		return min(a, b);
	}
	int n;
	vector<T> seg;
	void init(int _n) {
		n = _n;
		seg.assign(2*n, ID);
	}
	void pull(int p) {
		seg[p] = comb(seg[2*p], seg[2*p+1]);
	}

	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p/= 2) {
			pull(p);
		}
	}
	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra, seg[l++]);
			if (r&1) rb = comb(seg[--r], rb);
		}
		return comb(ra,rb);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int> > v(n, vector<int>(3, 0));
	set<int> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[i][j];
			s.insert(v[i][j]);
		}
		sort(v[i].begin(), v[i].end());
	}
	sort(v.begin(), v.end());
	map<int, int> m;
	int cnt = 0;
	for (int x : s) {
		m[x] = ++cnt;
	}
	Seg<int> seg;
	seg.init(3 * n + 1);
	map<int, multiset<int> > ms;
	for (int i = 0; i < n; i++) {
		ms[v[i][1]].insert(v[i][2]);
	}

	for (int i = 0; i < n; i++) {
		seg.upd(m[v[i][1]], *ms[v[i][1]].begin());
	}
	int ind = n - 1;
	string res = "No";
	for (int i = n - 1; i >= 0; i--) {
		while (ind >= 0 && v[ind][0] >= v[i][0]) {
			ms[v[ind][1]].erase(ms[v[ind][1]].find(v[ind][2]));	
			long long best = MAX;
			if (!ms[v[ind][1]].empty()) {
				best = *ms[v[ind][1]].begin();
			}
			seg.upd(m[v[ind][1]], best);
			ind--;
		}	
		if (seg.query(0, m[v[i][1]] - 1) < v[i][2]) {
			res = "Yes";
			break;
		}
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
