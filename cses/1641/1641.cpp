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
	long long n, x;
	cin >> n >> x;
	vector<pair<long long, int> > a(n);
	for (int i = 0; i < n; i++) {
		long long y;
		cin >> y;
		a[i] = {y, i};
	}
	sort(a.begin(), a.end());
	vector<int> res;
	
	for (int i = 0; i < n; i++) {
		int k = n - 1;
		if (res.size()) break;
		for (int j = i + 1; j < n; j++) {
			while (k > j && a[i].first + a[j].first + a[k].first > x) {
				k--;
			}
			if (k > j && a[i].first + a[j].first + a[k].first == x) {
				res = {a[i].second, a[j].second, a[k].second};
			}
		}
	}
	if (res.empty()) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << res[0] + 1 << " " << res[1] + 1 << " " << res[2] + 1 << endl;
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
