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

vector<vector<int> > dp(501, vector<int>(501, -1));

int solve(int a, int b) {
	if (dp[a][b] != -1) return dp[a][b];
	if (a == b) return dp[a][b] = 0;
	int res = 1e9;
	for (int i = 1; i < a; i++) {
		res = min(res, 1 + solve(i, b) + solve(a - i, b));
	}

	for (int i = 1; i < b; i++) {
		res = min(res, 1 + solve(a, i) + solve(a, b - i));
	}
	return dp[a][b] = res;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int a, b;
	cin >> a >> b;
	cout << solve(a, b) << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
