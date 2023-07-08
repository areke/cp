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
		int n, m;
		cin >> n >> m;
		vector<long long> v(n * m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> v[i * m + j];
			}
		}
		sort(v.begin(), v.end());
		long long res = (v[v.size() - 1] - v[0]) * max(n - 1, m - 1)  + (v[v.size() - 1] - v[1]) * min(n - 1, m - 1) + (v[v.size() - 1] - v[0]) * (n - 1) * (m - 1);
		reverse(v.begin(), v.end());
		res = max(res,  abs(v[v.size() - 1] - v[0]) * max(n - 1, m - 1)  + abs(v[v.size() - 1] - v[1]) * min(n - 1, m - 1) + abs(v[v.size() - 1] - v[0]) * (n - 1) * (m - 1));
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
