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
		string s;
		cin >> s;
		map<char, int> m;
		int maxi  = 0;
		for (int i = 0; i < n; i++) {
			m[s[i]]++;
			maxi = max(m[s[i]], maxi);
		}
		if (n % 2 == 1 || maxi > n / 2) {
			cout << -1 << endl;
			continue;
		}
		map<char, int> p;
		for (int i = 0; i < n / 2; i++) {
			if (s[i] == s[n - i - 1]) p[s[i]]++;
		}
		vector<int> v;
		for (auto it : p) {
			v.push_back(it.second);
		}
		if (v.empty()) {
			cout << 0 << endl;
			continue;
		}
		int res = 0;
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size() - 1; i++) {
			res += v[i];
		}
		if (res >= v[v.size() - 1]) {
			res += v[v.size() - 1];
			if (res % 2) {
				res = res / 2 + 1;
			} else {
				res /= 2;
			}
		} else {
			v[v.size() - 1] -= res;
			res += v[v.size() - 1];
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
