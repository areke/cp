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
	while (tests--) {
		int n, k;
		cin >> n >> k;
		string a, b;
		cin >> a >> b;
		map<char, int> m;
		for (int i = 0; i < n; i++) {
			if (!m.count(a[i])) {
				m[a[i]] = m.size();
			}
		}
		long long res = 0;
		//cout << m.size() << endl;

		for (int c = 0; c < (1 << m.size()); c++) {
			int cnt = 0;
			for (int i = 0; i < m.size(); i++) {
				if ((1 << i) & c) cnt++;
			}
			if (cnt > k) continue;
			long long cur = 0;
			long long len = 0;
			for (int i = 0; i < n; i++) {
				if (((1 << m[a[i]]) & c) || a[i] == b[i]) {
					len++;
				} else {
					cur += (len * (len + 1)) / 2;
					len = 0;
				}
			}
			cur += len * (len + 1) / 2;
			res = max(res, cur);
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
