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

//returns list of prime factors with their counts
vector<pair<long long, long long> > factor(long long a, vector<long long> & primes) {
	vector<pair<long long, long long> > res;
	for (int i = 0; i < primes.size(); i++) {
		int cnt = 0;
		while (a % primes[i] == 0) {
			cnt++;
			a /= primes[i];
		}
		if (cnt) {
			res.push_back({primes[i], cnt});
		}
	}
	if (a != 1) {
		res.push_back({a, 1});
	}
	return res;
}

void dfs(long long cur, int ind, vector<long long> & v, vector<long long> & c, vector<long long> & res) {
	if (ind == v.size()) {
		res.push_back(cur);
		return;
	}
	for (int i = 0; i <= c[ind]; i++) {
		dfs(cur, ind + 1, v, c, res);
		if (i != c[ind]) cur *= v[ind];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	// at most ~2^15 divisors
	// around 2^10 divisors

	// given prime factorization of d, find lowest factor of d such that d / f <= n
	// alternatively largest factor of d <= n

	// get all divisors, for each, iterate through all divisors <= n
	long long MAXN = 31623;
	vector<long long> p(MAXN + 1, 0);
	int pcnt = 0;
	for (int i = 2; i <= MAXN; i++) {
		if (!p[i]) {
			pcnt++;
			p[i] = 1;
		}
		for (int j = 2 * i; j <= MAXN; j+= i) {
			p[j] = 2;
		}
	}
	vector<long long> primes(pcnt);
	pcnt = 0;
	for (int i = 2; i <= MAXN; i++) {
		if (p[i] == 1) {
			primes[pcnt++] = i;
		}
	}
	while (tests--) {
		long long n, a, b;
		cin >> n >> a >> b;
		vector<pair<long long, long long> > av = factor(a, primes);
		vector<pair<long long, long long> > bv = factor(b, primes);
		map<long long, long long> m;
		for (int i = 0; i < av.size(); i++) {
			m[av[i].first] += av[i].second;
		}
		for (int i = 0; i < bv.size(); i++) {
			m[bv[i].first] += bv[i].second;
		}
		vector<long long> v(m.size());
		vector<long long> c(m.size());
		int cnt = 0;
		long long tot = 1;
		for (auto it : m) {
			v[cnt] = it.first;
			c[cnt] = it.second;
			tot *= (it.second + 1);
			cnt++;
		}
		long long cur = 1;
		vector<long long> d;
		dfs(cur, 0, v, c, d);
		vector<long long> s;

		sort(d.begin(), d.end());
		for (int i = 0; i < d.size(); i++) {
			//cout << d[i] << " ";
			if (d[i] <= n) s.push_back(d[i]);
		}
		//cout << endl;
		long long res1 = 0;
		long long res2 = 0;
		long long cind = 0;
		for (int i = 0; i < d.size(); i++) {
			for (int j = cind; j < s.size(); j++) {
				if (d[i] / s[j] > n) {
					cind++;
					continue;
				}
				if (d[i] % s[j] == 0) {
					//cout << d[i] << " " << j << endl;
					res1++;
					res2 ^= s[j];
					break;
				}
			}
		}
		cout << res1 << " " << res2 << endl;

		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
