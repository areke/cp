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
		long long n, p;
		cin >> n >> p;
		vector<long long> a(n + 1, 0);
		set<long long> s;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s.insert(a[i]);
		}
		int lm = -1;
		int hm = -1;
		for (int i = a[n] - 1; i >= max((long long)0, a[n] - 200); i--) {
			if (s.find(i) == s.end()) {
				lm = i;
				break;
			}
		}
		//cout << "TEST" << endl;
		long long res = 0;
		for (int i = p - 1; i > max(a[n], p - 200); i--) {
			if (s.find(i) == s.end()) {
				hm = max(hm, i);
				break;
			}
		}

		if (lm != -1) {
			res = p - a[n];
			a[n] = p - 1;
			for (int i = n; i >= 0; i--) {
				s.insert((a[i] + 1) % p);
				if (a[i] + 1 != p) {
					break;
				}
			}
			int o = lm;
			lm = 0;
			for (int i = o; i >= max(0, o - 300); i--) {
				if (s.find(i) == s.end()) {
					lm = i;
					break;
				}
			}
			res += lm;
		} else {
			if (hm != -1) {
				res = hm - a[n];
			}
		}
		cout << res << endl;

		

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
