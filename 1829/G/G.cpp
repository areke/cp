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

const int MAXN = 1000010;
vector<long long> dp(MAXN + 1, 0);

vector<int> row(MAXN + 1, 0);

vector<bool> vis(MAXN + 1, 0);
long long solve(long long x) {
	if (vis[x]) return dp[x];
	if (x <= 1) return x;
	vis[x] = 1;
	long long res = x * x;
	int left = x - row[x];
	int right = left + 1;
	if (row[left] == row[x] - 1) {
		res += solve(left);
	}
	if (row[right] == row[x] - 1) {
		res += solve(right);
	}
	if (row[left] == row[x] - 1 && row[right] == row[x] - 1) {
		int both = right - row[right];
		res -= solve(both);
	}
	return dp[x] =res;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	long long last = 0;
	for (long long i = 1; i <= 100000; i++) {
		if (last >= MAXN) break;
		for (int j = 1; j <= i; j++) {
			if (last + j >= MAXN) break;
			row[last + j] = row[last] + 1;
		}
		last += i;
	}

	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
