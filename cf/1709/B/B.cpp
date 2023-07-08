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
	int n, m;
	cin >> n >> m;
	vector<long long> v(n); 
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<long long> dp(n, 0);
	vector<long long> dp2(n, 0);
	for (int j = 1; j < n; j++) {
		dp[j] = dp[j - 1];
		if (v[j] < v[j - 1]) {
			dp[j] +=v[j - 1] - v[j];
		}
	}
	for (int j = n - 2; j >= 0; j--) {
		dp2[j] = dp2[j + 1];
		if (v[j] < v[j + 1]) {
			dp2[j] += v[j + 1] - v[j];
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if (x < y) {
			cout << dp[y] - dp[x] << endl;
		} else {
			cout << dp2[y] - dp2[x] << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
