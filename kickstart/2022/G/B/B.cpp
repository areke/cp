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
		long long s, h;
		cin >> s >> h;
		int n;
		cin >> n;
		vector<long long> a;
		for (int i = 0; i < n; i++) {
			long long x, y;
			cin >> x >> y;
			long long d = x * x + y * y;
			if (x * x + y * y <= (h + s) * (h + s)) {
				a.push_back(d);
			}
		}
		int m;
		cin >> m;
		vector<long long> b;
		for (int i = 0; i < m; i++) {
			long long x, y;
			cin >> x >> y;
			long long d = x * x + y * y;
			if (x * x + y * y <= (h + s) * (h + s)) {
				b.push_back(d);
			}
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		long long res1 = 0, res2=0;
		if (a.empty() || b.empty()) {
			res1 = a.size();
			res2 = b.size();
		} else {
			int p = 0;
			while (p < a.size() && a[p] < b[0]) {
				res1++;
				p++;
			}
			p = 0;
			while (p < b.size() && b[p] < a[0]) {
				res2++;
				p++;
			}
		}
		cout << "Case #" << test << ": " << res1 << " " << res2 << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
