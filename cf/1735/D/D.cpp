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
#include <queue>
#include <list>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

long long rep(vector<int> & v) {
	long long res = 0;
	long long p = 1;
	for (int i = v.size() - 1; i >= 0; i--) {
		res += v[i] * p;
		p *= 3;
	}
	return res;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int> > c(n);
	unordered_set<long long> sl;
	for (int i = 0; i < n; i++) {
		vector<int> v(k);
		long long cur = 0;
		long long p = 1;
		for (int j = 0; j < k; j++) {
			cin >> v[j];
		}
		c[i] = (v);
		sl.insert(rep(v));
	}
	unordered_map<long long, long long> m;
	map<pair<long long, long long>, long long > sets;
	for (int i = 0; i < n; i++) {
		long long ir = rep(c[i]);
		for (int j = i + 1; j < n; j++) {
			vector<int> v(k, 0);
			for (int l = 0; l < k; l++) {
				if (c[i][l] == c[j][l]) {
					v[l] = c[i][l];
				} else {
					v[l] = 3 - c[i][l] - c[j][l];
				}
			}
			long long jr = rep(c[j]);
			long long vr = rep(v);
			if (sl.find(vr) != sl.end()) {
				m[vr]++;
				sets[make_pair(ir, jr)] = vr;
			}
		}
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		long long ir = rep(c[i]);
		for (int j = i + 1; j < n; j++) {
			long long jr = rep(c[j]);
			if (m[ir] == 0 || m[jr] == 0) continue;
			if (sets.count(make_pair(ir, jr))) {
				long long vr = sets[make_pair(ir, jr)];
				cout << ir << " " << jr << " " << vr << " " << m[ir] << " " << m[jr] << endl;
				res += m[ir] + m[jr] - 2;
			}
		}
	}
	cout << res / 4 << endl;
	return 0;
}
