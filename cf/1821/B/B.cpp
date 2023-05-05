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
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		vector<int> v;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				v.push_back(i);
			}
		}
		if (v.size()) {
			int l = v[0];
			int r = v[v.size() - 1];
			while (l > 0 && b[l - 1] <= b[l]) {
				l--;
			}
			while (r < n - 1 && b[r + 1] >= b[r]) {
				r++;
			}
			cout << l + 1 << " " << r + 1 << endl;
		} else {
			int best = 0;
			int res = 1;
			int cnt = 1;
			for (int i = 1; i < n; i++) {
				if (b[i] >= b[i - 1]) {
					cnt++;
				} else {
					if (cnt > res) {
						res = cnt;
						best = i - cnt - 1;
					}
					cnt = 1;
				}
			}
			if (cnt > best) {
				res = cnt;
				best = n - cnt - 1;
			}
			cout << best + 1 << " " << best + 1 + res << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
