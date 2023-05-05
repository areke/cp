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
vector<pair<long long, long long> > factor(long long a, vector<long long> & all) {
	vector<pair<long long, long long> > res;
	for (int j = 0; j < all.size(); j++) {
		if (all[j] > sqrt(a)) break;
		int cnt = 0;
		while (a % all[j] == 0) {
			cnt++;
			a /= all[j];
		}
		if (cnt) {
			res.push_back({all[j], cnt});
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
	int tests;
	long long MAXN = sqrt(1e9);
	vector<int> p(MAXN + 5, 0);
	for (int i = 2; i <= MAXN + 1; i++) {
		if (!p[i]) p[i] = 1;
		for (int j = 2 * i; j <= MAXN + 1; j+= i) {
			p[j] = 2;
		}
	}
	vector<long long> all;
	for (int i = 2; i <= MAXN + 1; i++) {
		if (p[i] == 1) {
			all.push_back(i);
		}
	}
	cin >> tests;
	while (tests--) {
		long long n;
		cin >> n;
		vector<pair<long long, long long> > v = factor(n, all);
		long long res = 0;
		bool b = true;
		while (b) {
			b = false;
			long long cur = 1;
			for (auto & it : v) {
				if (it.second >= 1) {
					cur *= it.first;
					it.second--;
					b = true;
				}
			}
			if (b) res += cur;
		}
		cout << res << endl;


	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
