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
	int n;
	cin >> n;
	vector<long long> res(n + 1, 1e18);
	res[0] = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		int ind = lower_bound(res.begin(), res.end(), x) - res.begin();
		ans = max(ind, ans);
		res[ind] = min(res[ind], x);
	}
	cout << ans << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
