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
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<long long> a;
		long long cur = 1e10;
		for (int i = 0; i < n; i++) {
			if (v[i] == 0) continue;
			if (cur == 1e10) {
				cur = v[i];
			} else {
				if (abs(cur) / cur == abs(v[i]) / v[i]) {
					cur += v[i];
					if (i == n - 1) a.push_back(cur);
				} else {
					a.push_back(cur);
					cur = v[i];
				}
			}
		}
		list<long long> l;
		for (int i = 0; i < a.size(); i++) {
			l.push_back(a[i]);
		}
		map<long long, vector<int> > m;
		for (int i = 0; i < a.size(); i++) {
			
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
