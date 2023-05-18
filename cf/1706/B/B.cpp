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
		int n;
		cin >> n;
		vector<int> c(n);
		for (int i = 0; i < n; i++) {
			cin >> c[i];
			c[i]--;
		}
		vector<vector<int> > dp(n, vector<int>(2, 0));
		for (int i = 0; i < n; i++) {
			dp[c[i]][i % 2] = max(dp[c[i]][i % 2], dp[c[i]][(i + 1) % 2] + 1);
		}
		for (int i = 0; i < n; i++) {
			cout << max(dp[i][0], dp[i][1]) << " \n"[i == n - 1];
		}


	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
