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
#include <unordered_map>
#include <unordered_set>
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
		string s, t;
		cin >> s >> t;
		vector<char> a, b;
		a = {s[0]};
		b = {t[0]};
		int ca = 1;
		int da = 1;
		vector<int> c;
		vector<int> d;
		for (int i = 1; i < n; i++) {
			if (s[i] != a[a.size() - 1]) {
				a.push_back(s[i]);
				c.push_back(ca);
				ca = 0;

			}
			if (t[i] != b[b.size() - 1]) {
				b.push_back(t[i]);
				d.push_back(da);
				da = 0;
			}
			ca++;
			da++;
		}
		if (ca) c.push_back(ca);
		if (da) d.push_back(da);
		bool can = true;
		if (a.size() != b.size()){
			can = false;
		}
		if (!can) {
			cout << -1 << endl;
			continue;
		}

		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) can = false;
		}
		if (!can) {
			cout << -1 << endl;
			continue;
		}
		long long res = 0;
		for (int i = 0; i < c.size(); i++) {
			if (i == c.size() - 1) assert(c[i] == d[i]);
			if (d[i] > c[i]) {
				res += d[i] - c[i];
				c[i + 1] -= d[i] - c[i];
			} else if (d[i] < c[i]) {
				res += c[i] - d[i];
				c[i + 1] += c[i] - d[i];
			}
		}
		
		cout << res << endl;



	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
