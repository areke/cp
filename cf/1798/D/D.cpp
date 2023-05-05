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
		int n;
		cin >> n;
		vector<long long> o(n);
		vector<long long> v(n);
		long long mini = 1e10;
		long long maxi = -1e10;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			o[i] = v[i];
			mini = min(mini, v[i]);
			maxi = max(maxi, v[i]);
		}
		long long range = maxi - mini;
		sort(v.begin(), v.end());
		int l = 0;
		int r = n - 1;
		long long cur = 0;
		bool can = true;
		vector<int> res(n, -1);
		int p = 0;
		long long big = 0;
		long long small = 0;
		long long tot = 0;
		while (l <= r) {
			int lr = r;
			int ll = l;
			cur = 0;
			while (l <= r && abs(cur + v[l]) < range && abs(tot - small + v[l]) < range && abs(tot - big + v[l]) < range ) {
				res[p++] = l;
				tot += v[l];
				cur += v[l++];
			}
			small = min(small, tot);
			big = max(big, tot);
			cur = 0;
			while (l <= r && abs(cur + v[r]) < range && abs(tot - big + v[r]) < range  && abs(tot - small + v[r]) < range) {
				res[p++] = r;
				tot += v[r];
				cur += v[r--];
			}
			small = min(small, tot);
			big = max(big, tot);
			//cout << l << " " << r << " " << tot << endl;
			if (lr == r && ll == l) {
				can = false;
				break;
			}
		}
		if (!can) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
			for (int i = 0; i < n; i++) {
				cout << v[res[i]];
				if (i == n - 1) cout << endl;
				else cout << " ";
			}
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
