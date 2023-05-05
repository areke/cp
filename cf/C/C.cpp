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

bool isPrime(long long x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) return false;
	}
	return true;
}

//returns list of prime factors with their counts
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> p(101, 0);
		for (int i = 2; i <= 100; i++) {
			if (!p[i]) p[i] = 1;
			for (int j = 2 * i; j <= 100; j+=i) {
				p[j] = 2;
			}
		}
		vector<long long> v;
		for (int i = 0; i < n; i++) {
			vector<pair<long long, long long> > f = factor(a[i]);
			map<long long, int> m;
			for (int j = 0; j < f.size(); j++) {
				m[f[j].first] = f[j].second;
			}
			//cout <<i << endl;
			long long c = 0;
			long long d = 1;
			for (int j = 2; j <= 100; j++) {
				if (p[j] != 1) continue;
				c += (1 << d) * (m[j] % 2);
				d++;
			}
			//if (a[0] == 2) cout << c << endl;
			v.push_back(c);
		}
		vector<long long> b;
		for (int i = 0; i < n; i++) {
			vector<long long> c = {v[i]};
			b = merge(b, c);
		}
		long long res = 1;
		int ns = (n - b.size());
		//cout << n << " " << b.size() << " " << ns << endl;
		long long MOD = 1e9 + 7;
		for (int i = 0; i < ns; i++) {
			res *= 2;
			res %= MOD;
		}
		res--;
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
