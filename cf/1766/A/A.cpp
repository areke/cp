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

bool round(int x) {
	int cnt = 0;
	while (x) {
		cnt += (x % 10 !=0);
		x /= 10;
	}
	return cnt == 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> dp(1000000, 0);
	for (int i = 1; i <= 999999; i++) {
		if (round(i)) {
			dp[i] = 1;
		}
		dp[i] += dp[i - 1];
	}
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
