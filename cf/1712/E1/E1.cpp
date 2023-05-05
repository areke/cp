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




template<class T> struct Seg {
	const T ID = 0;
	T comb(T a, T b) {
		return a + b;
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

	T get(int p) {
		return seg[n + p];
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

long long gcd(long long a, long long b) {
	return (a == 0 ? b : gcd(b % a, a));
}

long long lcm(long long a, long long b, long long c) {
	long long l = a * b / gcd(a, b);
	return l * c / gcd(l, c);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int> > v(4e5 + 1);

	for (int i = 1; i < v.size(); i++) {
		for (int j = i; j < v.size(); j += i) {
			v[j].push_back(i);
		}
	}
	//cout << cnt << endl;
	int tests;
	cin >> tests;
	vector<array<int, 3> > t;
	for (int test = 0; test < tests; test++) {
		int l, r;
		cin >> l >> r;
		t.push_back({l, r, test});
	}
	Seg<int> seg;
	seg.init(2e5 + 1);
	map<pair<int, int>, int> s;

	for (int i = 1; i <= v.size() / 2; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			s[{v[i][j], i}] += max(0, (int)v[i].size() - j - 2);
		} 
		//cout << i << " 1" << endl;
		if (2 * i < v.size()) {
			for (int j = 0; j < v[2 * i].size() - 2; j++) {
				for (int k = j + 1; k < v[2 * i].size() - 2; k++) {
					if (v[2 * i][j] < i && v[2 * i][k] < i && v[2 * i][j] + v[2 * i][k] > i) {
						if (lcm(v[2 * i][j], v[2 * i][k], i) == 2 * i) {
							s[{v[2 * i][j], i}]++;
						}
					}
				}
			}
		}
		//cout << i << " 2" << endl;
	}

	//cout << "HUdddddH " << s.size() << endl;
	sort(t.begin(), t.end());
	auto ind = s.rbegin();
	vector<long long> res(t.size());
	for (int i = tests - 1; i >= 0; i--) {
		while (ind != s.rend() && ind->first.first >= t[i][0]) {
			seg.upd(ind->first.second, seg.get(ind->first.second) + ind->second);
			ind++;
		}
		long long cnt = t[i][1] - t[i][0] + 1;
		
		res[t[i][2]] = cnt * (cnt - 1) * (cnt - 2) / 6 - seg.query(0, t[i][1]);
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
