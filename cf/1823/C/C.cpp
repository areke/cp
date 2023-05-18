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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		map<long long, long long> m;
		for (int i = 0; i < n; i++) {
			vector<pair<long long, long long> > f = factor(v[i]);
			for (auto & p : f) {
				m[p.first] += p.second;
			}
		}
		long long res = 0;
		for (auto it: m) {
			res += it.second / 2;
			m[it.first] = it.second % 2;
		}
		long long cnt = 0;
		for (auto it : m) {
			cnt += it.second;
		}
		res += cnt / 3;
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
