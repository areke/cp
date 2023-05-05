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
		vector<pair<long long, long long> > v(n);
		pair<long long, long long> first;
		for (int i = 0; i < n; i++) {
			long long a, b;
			cin >> a >> b;
			v[i] = {a, b};
		}
		long long best = -1;
		for (int i = 1; i < n; i++) {
			if (v[i].first >= v[0].first) {
				best = v[0].first + v[0].second;
			}
		}
		if (best != -1) {
			if (best >= k) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
			continue;
		}
		sort(v.begin() + 1, v.end());
		long long h = -1e18;
		for (int i = 1; i < n; i++) {
			if (i == 1) h = v[i].first;
			else {
				h = max(h, min(h, v[i].first) + v[i].second);
				h = max(h, v[i].first);
			}
			if (i > 1) {
				h = max(h, v[i - 1].first + v[i - 1].second);
			}
		}
		best = max(min(h, v[0].first) + v[0].second, v[0].first);
		if (best >= k) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
