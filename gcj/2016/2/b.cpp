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
  int curtest = 1;
	while (tests--) {
		cout << "Case #" << curtest << ": ";
    curtest++;
    int n, k;
    cin >> n >> k;
    vector<long double> v(n);
    vector<vector<long double> > dp(n + 1, vector<long double>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
      
      for (int j = 0; j < n; j++) {
        for (int l = 0; l < k /2 + 1; l++) {
          dp[j + 1][l + 1] = max(dp[j][l] * v[i], dp[j + 1][l + 1]);
          dp[j + 1][l] = max(dp[j][l] * (1 - v[i]), dp[j + 1][l]);
        }
      }
    }
    cout << dp[n][k / 2] << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
