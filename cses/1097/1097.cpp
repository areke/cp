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
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

vector<vector<long long> > dp(5001, vector<long long>(5001, 0));

vector<long long> p(5001, 0);



vector<vector<bool > > vis(5001, vector<bool>(5001, 0));

long long solve(int l, int r) {
	if (l > r) return 0;
	if (vis[l][r]) return dp[l][r];
	vis[l][r] = true;
	long long res = max(p[r + 1] - p[l] - solve(l + 1, r), p[r + 1] - p[l] - solve(l, r - 1));
	return dp[l][r] = res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i] + a[i];
	}
	cout << solve(0, n - 1) << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
