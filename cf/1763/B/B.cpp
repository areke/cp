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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n, k;
		cin >> n >> k;
		vector<long long> h(n);
		vector<long long> p(n);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		vector<pair<long long, long long> > v(n);
		for (int i = 0; i < n; i++) {
			v[i] = {h[i], p[i]};
		}
		sort(v.begin(), v.end());
		vector<long long> minp(n, 1e6);
		minp[n - 1] = v[n-1].second;
		for (int i = n - 2; i >= 0; i--) {
			minp[i] = min(minp[i +1], v[i].second);
		}
		int ind = 0;
		long long sub = 0;
		while (ind < n && k > 0) {
			while (ind < n && v[ind].first <= k + sub) {
				ind++;
			}
			if (ind < n) {
				sub += k;
				k -= minp[ind];
			}
		}
		if (ind == n) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
