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
		string s;
		cin >> s;
		bool all = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] =='0') all = false;
		}
		if (all) {
			long long cnt = s.length();
			cout << cnt * cnt << endl;
			continue;
		}
		long long res = 0;
		long long cnt = 0;
		vector<long long> v;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '1') {
				cnt++;
			} else {
				v.push_back(cnt);
				cnt = 0;
			}
		}
		if (cnt) {
			v.push_back(cnt);
		}
		for( long long x : v) {
			if (x % 2) {
				res = max(res, (x / 2 + 1) * (x / 2 + 1));
			} else {
				res = max(res, (x / 2) * (x / 2 + 1));
			}
		}
		if (s[0] == '1' && s[s.length() -1] == '1' && v.size() > 1) {
			cnt = v[0] + v[v.size() - 1];
			if (cnt % 2) {
				res = max(res, (cnt / 2 + 1) * (cnt / 2 + 1));
			} else {
				res = max(res, (cnt / 2) * (cnt / 2 + 1));
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
