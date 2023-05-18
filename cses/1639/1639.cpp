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
	string s, t;
	cin >> s >> t;
	vector<vector<int> > dp(s.length() + 1, vector<int>(t.length() + 1, 1e9));
	dp[0][0] = 0;
	for (int i = 1; i <= s.length(); i++) {
		dp[i][0] = i;
	}
	for (int i = 1; i <= t.length(); i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= s.length(); i++) {
		for (int j = 1; j <= t.length(); j++) {
			
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
				
			}
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}
	long long res = dp[s.length()][t.length()];
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
