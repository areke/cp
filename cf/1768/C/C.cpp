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
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		vector<pair<int, int> > v(n);
		for (int i = 0; i < n; i++) {
			v[i] = {p[i], i};
		}
		sort(v.begin(), v.end());
		vector<int> a(n);
		vector<int> b(n);
		set<int> as;
		set<int> bs;
		int cur = 1;
		bool can = true;
		for (int i = 0; i < n; i++) {
			while (cur <= v[i].first && cur <= n) {
				as.insert(cur);
				bs.insert(cur);
				cur++;
			}
			if (as.find(v[i].first) == as.end() && bs.find(v[i].first) == bs.end()) {
				can = false;
				break;
			}
			if (bs.find(v[i].first) != bs.end()) {
				swap(as, bs);
				swap(a, b);
			}
			a[v[i].second] = v[i].first;
			as.erase(as.find(v[i].first));
			if (bs.empty()) {
				can = false;
				break;
			}
			b[v[i].second] = *(bs.begin());
			bs.erase(bs.begin());
		}
		if (can) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			for (int i= 0; i < n; i++) {
				cout << b[i] << " ";
			}
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
