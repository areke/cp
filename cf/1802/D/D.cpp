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
		int n;
		cin >> n;
		vector<pair<long long, long long> > v(n);
		for (int i = 0; i < n; i++) {
			long long a, b;
			cin >> a >> b;
			v[i] = {a, b};
		}
		
		sort(v.begin(), v.end());
		vector<long long> maxi(n);
		maxi[n - 1] = v[n - 1].second;
		for (int i = n - 2; i >= 0; i--) {
			maxi[i] = max(maxi[i + 1], v[i].second);
		}
		long long res = 1e18;
		set<long long> s;
		set<long long> r;
		for (int i = 0; i < n; i++) {
			long long b = -1e18;
			long long a = v[i].first;
			if (i < n - 1) {
				b = maxi[i + 1];
			}
			long long cur = abs(a - b);
			auto it = s.lower_bound(a);
			if (it != s.end()) {
				
				if ((*it) >= b) cur = min(cur,abs(a - *it));
			}
			auto rit = r.lower_bound(-a);
			if (rit != r.end()) {
				if (-(*rit) >= b) cur = min(cur, abs(a + *rit));
			}
			res = min(res, cur);
			s.insert(v[i].second);
			r.insert(-v[i].second);
		}
		cout << res << endl;
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}