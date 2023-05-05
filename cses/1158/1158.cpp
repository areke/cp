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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n, x;
	cin >> n >> x;
	vector<long long> h(n);
	vector<long long> s(n); 	
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	vector<long long> dp(x + 1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = x; j >= 0; j--) {
			if (j + h[i] > x) continue;
			dp[j + h[i]] = max(dp[j + h[i]], dp[j] + s[i]);
		}
	}
	long long res = 0;
	for (int i =0 ; i <= x; i++) {
		res = max(res, dp[i]);
	}
	cout << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
