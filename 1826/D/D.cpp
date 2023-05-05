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
		int n;
		cin >> n;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		multiset<long long> left;
		multiset<long long> right;
		for (int i = n - 1; i > 1; i--) {
			right.insert(v[i] - i);
		}
		left.insert(v[0] + 0);
		long long res = -1e18;
		for (int i = 1; i < n - 1; i++) {
			if (i > 1) right.erase(right.find(v[i] - i));
			long long lm = *left.rbegin();
			long long rm = *right.rbegin();
			long long cur = lm + rm + v[i];
			res = max(res, cur);
			left.insert(v[i] + i);
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
