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
		unsigned long long n, x;
		cin >> n >> x;
		vector<int> nv;
		vector<int> xv;
		unsigned long long p = 1;
		unsigned long long cnt = 0;
		bool can = true;
		while (p <= n || p <= x) {
			if (p & n) {
				nv.push_back(1);
			} else {
				nv.push_back(0);
			}
			if (p & x) {
				xv.push_back(1);
			} else {
				xv.push_back(0);
			}
			cnt++;
			p *= 2;
		}
		for (int i = 0; i < xv.size(); i++) {
			if (xv[i] == 1 && nv[i] == 0) can = false;
		}
		if (!can) {
			cout << -1 << endl;
			continue;
		} 
		if (n == x) {
			cout << n << endl;
			continue;
		}
		reverse(nv.begin(), nv.end());
		reverse(xv.begin(), xv.end());
		p = 1;
		unsigned long long res = 0;
		can = false;
		for (int i = nv.size() - 1; i >= 0; i--) {
			long long nm = ((p * 2) - 1) & (n);
			long long add = p * 2 - nm;
			if (((n + add) & n) == x) {
				res = n + add;
				can = true;
				break;
			}
			p *= 2;
		}
		if (!can) {
			cout << -1 << endl;
			continue;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
