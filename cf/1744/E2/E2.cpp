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

bool isPrime(long long x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) return false;
	}
	return true;
}

vector<pair<long long, long long> > factor(long long a) {
	vector<pair<long long, long long> > res;
	for (int j = 2; j <= sqrt(a); j++) {
		if (!isPrime(j)) continue;
		int cnt = 0;
		while (a % j == 0) {
			cnt ++;
			a /= j;
		}
		if (cnt) {
			res.push_back({j, cnt});
		}
	}
	if (a != 1) {
		res.push_back({a, 1});
	}
	return res;
}


// z * a * b
// z > 1 
// c >= 2 * a && d >= 2 * b... 2 * a, 2 * b

// c < 2 * a, d < 2 * b
// z = 2 or 3

// c >= 2 * a, d < 2 * b


void solve(int ind, vector<pair<long long, long long> > & v, long long cur, set<long long> & div) {
	if (ind == v.size()) {
		div.insert(cur);
		return;
	}
	for (int i = 0; i < v[ind].second; i++) {

		solve(ind + 1, v, cur, div);
		cur *= v[ind].first;
	}
	solve(ind + 1, v, cur, div);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		vector<pair<long long, long long> > f = factor(a);
		vector<pair<long long, long long> > f2 = factor(b);
		map<long long, int> m;
		for (int i = 0; i < f.size(); i++) {
			m[f[i].first] += f[i].second;
		}
		for (int i = 0; i < f2.size(); i++) {
			m[f2[i].first] += f2[i].second;
		}
		vector<pair<long long, long long> > v;
		for (auto it : m) {
			v.push_back({it.first, it.second});
		}
		set<long long> div;
		solve(0, v, 1, div);
		long long x = -1;
		long long y = -1;
		for (auto it : div) {
			//cout << it << " " ;
			long long xx = it;
			long long yy = a * b / xx;
			if ((a / xx + 1) * xx <= c && (b / yy + 1) * yy <= d) {
				x = (a / xx + 1) * xx;
				y = (b / yy + 1) * yy;
			}
		}
		cout << x << " " << y << endl;


	}
	return 0;
}
