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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		// assume min is j
		int res = 1e9;
		sort(a.begin(), a.end());
		set<int> pos;
		for (int i = 0; i <= sqrt(100000) + 1; i++) {
			pos.insert(i);
		}
		for (int i = 1; i <= 100000; i++) {
			pos.insert(a[a.size() - 1]/ i);
		}
		for (int j : pos) {
			int mini = 1e9;
			int maxi = 0;
			if (j > 0) {
				for (int i = 0; i < n; i++) {
					int p = max(1, min(k, a[i] / j));
					maxi = max(maxi, a[i] / p);
					mini = min(mini, a[i] / p);
				}
			} else {
				for (int i = 0; i < n; i++) {
					int p = min(k, a[i] + 1);
					maxi = max(maxi, a[i] / p);
					mini = min(mini, a[i] / p);
				}
			}
			
			res = min(res, maxi - mini);
			
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
