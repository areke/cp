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
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);

		long long s = 0;
		long long res = -1e18;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < n; i++) {
			s += v[i];
		}
		sort(v.begin(), v.end());
		vector<long long> l(k + 1, 0);
		vector<long long> r(k + 1, 0);
		r[0] = 0;
		for (int i = 0; i < k; i++) {
			l[i + 1] = l[i] + v[2 * i] + v[2 * i + 1];
		}
		for (int i = 0; i < k; i++) {
			r[i + 1] = r[i] + v[n - i - 1];
		}
		for (int i = 0; i <= k; i++) {
			res = max(res, s - (l[i] + r[k - i]));
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
