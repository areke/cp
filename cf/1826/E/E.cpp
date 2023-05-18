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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;


long long solve(int x, vector<bitset<5000> > & b, vector<long long> & p, vector<long long> & dp) {
	if (dp[x] != -1) return dp[x];
	int n = p.size();
	long long res = p[x];
	for (int i = 0; i < n; i++) {
		if (i == x) continue;
		if (b[x].test(i)) {
			res = max(res, p[x] + solve(i, b, p, dp));
		}
	}
	return dp[x] = res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	vector<long long> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	vector<vector<pair<long long, int> > > v(m, vector<pair<long long, int> >(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j].first;
			v[i][j].second = j;
		}
		sort(v[i].begin(), v[i].end());
	}
	vector<bitset<5000> > b(n);
	for (int i = 0; i < n; i++) {
		b[i].set();
	}
	for (int i = 0; i < m; i++) {
		bitset<5000> ok;
		ok.set();
		for (int j = 0, k = 0; j < n; j++) {
			while (k < n && v[i][k].first == v[i][j].first) ok.flip(v[i][k++].second);
			b[v[i][j].second] &= ok;
		}
	}
	vector<long long> dp(n, -1);
	for (int i = 0; i < n; i++) {
		solve(i, b, p, dp);
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, dp[i]);
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
