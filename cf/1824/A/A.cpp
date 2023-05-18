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
		set<int> s;
		int l = 0;
		int r = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if(x == -1) {
				l++;
			} else if (x == - 2) {
				r++;
			} else {
				s.insert(x);
			}
		}
		vector<int> v(s.begin(), s.end());
		int res = 0;
		if (l > 0) {
			res = min(m, (int)v.size() + l);
		}
		if (r > 0) {
			res = max(res, min(m, (int)v.size() + r));
		}
		for (int i = 0; i < v.size(); i++) {
			int left = v[i] - i - 1;
			int right = m - v[i] - (v.size() - i - 1);
			left = min(left, l);
			right = min(right, r);
			res = max(res, left + right + (int)v.size());
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
