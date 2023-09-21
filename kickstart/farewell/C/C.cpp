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
	for (int test = 1; test <= tests; test++) {
		int n, k;
		cin >> n >> k;
		vector<pair<long long, int> > v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].first;
			v[i].second = i;
		}
		sort(v.begin(), v.end());
		vector<long long> l(n, 0);
		vector<long long> r(n, 0);
		int cur = 0;
		long long last = -1e18;
		for (int i = 0; i < n; i++) {
			if (v[i].first - last >= k) {
				cur++;
				last = v[i].first;
			}
			l[v[i].second] = cur;
		}
		cur = 0;
		last = 1e18;
		for (int i = n - 1; i >= 0; i--) {
			if (last - v[i].first >= k) {
				cur++;
				last = v[i].first;
			}
			r[v[i].second] = cur;
		}
		cout << "Case #" << test << ": ";
		for (int i = 0; i < n; i++) {
			cout << l[i] + r[i] - 1;
			if (i == n -1) cout << endl;
			else cout << " ";
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
