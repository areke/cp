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
		vector<int> v(n);
		set<int> s;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			s.insert(v[i]);
		}
		int mex = 0;
		for (int i = 0; i <= n; i++) {
			if (s.find(i) == s.end()) break;
			mex++;
		}
		if (mex == n) {
			cout << "No" << endl;
			continue;
		}
		int mex2 = mex + 1;
		set<int> bad;
		int r = -1;
		int l = n;
		for (int i = 0; i < n; i++) {
			if (v[i] == mex2) {
				r = max(i, r);
				l = min(i, l);
			}
		}
		if (l > r) {
			cout << "Yes" << endl;
		} else {
			set<int> ns;
			for (int i = 0; i < l; i++) {
				ns.insert(v[i]);
			}
			for (int i = r + 1; i < n; i++) {
				ns.insert(v[i]);
			}
			int nm = 0;
			for (int i = 0; i <= n; i++) {
				if (ns.find(i) == ns.end()) break;
				nm++;
			}
			if (nm == mex) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
		

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
