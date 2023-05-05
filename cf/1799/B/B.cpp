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
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		bool one = false;
		bool high = false;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) one = true;
			else high = true;
		}
		if (one && high) {
			cout << -1 << endl;
			continue;
		}
		bool equal = true;
		for (int i = 1; i < n; i++) {
			if (a[i] != a[i - 1]) equal = false;
		}
		if (equal) {
			cout << 0 << endl;
			continue;
		}
		vector<pair<long long, int> > v(n);
		for (int i = 0; i < n; i++) {
			v[i] = {a[i], i};
		}
		sort(v.begin(), v.end());
		vector<pair<int, int> > res;
		bool can = false;
		while (!can) {
			equal = true;
			for (int i = 1; i < n; i++) {
				if (v[i].first != v[i - 1].first) equal = false;
			}
			if (equal) break;
			sort(v.begin(), v.end());
			int i = v.size() - 1;
			int j = 0;
			long long x = v[i].first / v[j].first;
			if (v[i].first % v[j].first != 0) x++;
			v[i].first = x;
			res.push_back({v[i].second + 1, v[j].second + 1});
		}
		for (int i = 1; i < n; i++) {
			assert(v[i].first == v[i - 1].first);
		}
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i].first << " " << res[i].second << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
