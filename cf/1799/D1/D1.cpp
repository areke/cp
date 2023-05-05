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
		int n, k;
		cin >> n >> k;
		vector<long long> a(n);
		vector<long long> c(k);
		vector<long long> h(k);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
		}
		for (int i = 0; i < k; i++) {
			cin >> c[i];
		}
		for (int i = 0; i < k; i++) {
			cin >> h[i];
		}
		vector<int> v;
		long long res = 0;
		v.push_back(a[0]);
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i - 1]) {
				res += h[a[i]];
			} else {
				v.push_back(a[i]);
			}
		}
		map<long long, int> m;
		vector<long long> p(v.size() + 1, 0);
		vector<long long> dp(v.size());
		for (int i = 1; i <= v.size(); i++) {
			p[i] += p[i - 1] + c[v[i - 1]];
		}
		//cout << "HUH" << endl;
		dp[0] = c[v[0]];
		m[v[0]] = 0;
		for (int i = 1; i < v.size(); i++) {
			//cout << i << endl;
			if (m.count(v[i])) {
				int l = m[v[i]];
				dp[i] = dp[i - 1] + c[v[i]];
				dp[i] = min(dp[i], dp[l + 1] + p[i] - p[l + 2] + h[v[i]]);
			} else {
				dp[i] = dp[i - 1] + c[v[i]];
			}
			m[v[i]] = i;
		}
		res += dp[v.size() - 1];
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
