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
#include <queue>
#include <list>
#include <cstring>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<vector<long long> > dp(n, vector<long long>(2, 0));
		if (s[0] == '1') {
			dp[0][1] = a[0];
		}
		for (int i = 1; i < n; i++) {
			if (s[i] == '1') {
				dp[i][1] = max(a[i] + dp[i - 1][1], a[i] + dp[i - 1][0]);
				dp[i][0] = dp[i - 1][0] + a[i - 1];
			} else {
				dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
				dp[i][1] = 0;
			}
		}
		cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
	}
	return 0;
}
